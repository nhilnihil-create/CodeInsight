#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
long mod = 1e9+7;
int main(){
    long n,ans=1,x=-1,y=-1,z=-1;
    cin >> n;
    rep(i,n){
        int a;
        cin >> a;
        int cnt = 0;
        int flag = 0;
        if(a==x+1){
            cnt++;
            flag++;
        }
        if(a==y+1){
            cnt++;
            flag += 2;
        } 
        if(a==z+1){
            cnt++;
            flag += 4;
        }
        ans = ans*cnt%mod;
        if(flag==1||flag==3||flag==7) x++;
        if(flag==2||flag==6) y++;
        if(flag==4||flag==5) z++;
    } 
    cout << ans << endl;
}