#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

int main(){
    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    if(10%p==0){
        ll ans = 0;
        rep(i,n){
            int d = s[i] - '0';
            if(d%p ==0){
                ans += i+1;
            }
        }
        cout << ans << endl;
    }else{
        ll ans = 0;
        vector<int> res(p,0);
        res[0] ++;
        int now = 0;
        int t = 1;
        for(int i=n-1;i>=0;i--){
            now = (now + (s[i] - '0') * t)%p;
            ans += res[now];
            ++res[now];
            t = (t * 10)%p;
        }
        cout << ans << endl; 
    }
    return 0;
}