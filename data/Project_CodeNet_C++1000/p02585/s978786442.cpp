#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using itn = int;

int main(void){
    int n,k;
    cin >> n >> k;
    
    long long p[n],c[n];
    for(int i = 0;i < n;i++)cin >> p[i];
    for(int i = 0;i < n;i++)cin >> c[i];
    
    for(int i = 0;i < n;i++)p[i]--;
    
    long long ans = -1e18;
    if(k <= 4*n){
        for(int i = 0;i < n;i++){
            int now = p[i];
            long long score = 0;
            
            for(int j = 0;j < k;j++){
                now = p[now];
                score += c[now];
                ans = max(ans,score);
            }
        }
    } else {
        for(int i = 0;i < n;i++){
            int now = p[i],syuuki = 0,memo = now;
            long long score = 0;
            
            for(int j = 0;j < 2*n;j++){
                if(j > 0 && memo == now)break;
                now = p[now];
                score += c[now];
                ans = max(ans,score);
                syuuki++;
            }
            
            score = score * ((k / syuuki) - 1);
            now = p[i];
            ans = max(ans,score);
            long long score2 = 0;
            
            for(int j = 0;j < (k % syuuki) + syuuki;j++){
                now = p[now];
                score2 += c[now];
                ans = max(ans,score + score2);
            }
        }
    }
    cout << ans << endl;
}
