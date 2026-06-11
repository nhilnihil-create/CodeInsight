#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
void solve(){
    int n,m;
    cin>>n>>m;
    int r=n/2;
    if(r%2!=0) r--;
    int x=r/2;
    int y=x+1;
    while(m>0 && x>=1 && y<=r){
        if(2*abs(x-y)==n){
            x--; y++;
            continue;
        }
        cout<<x<<' '<<y<<'\n';
        x--; y++;
        m--;
    }
    int g=n-r;
    x=r+g/2;
    y=x+2;
    while(m>0){
        if(2*abs(x-y)==n){
            x--; y++;
            continue;
        }
        cout<<x<<' '<<y<<'\n';
        x--; y++;
        m--;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int tc;
 //   cin>>tc;
    tc=1;
    while(tc--){
        solve();
    }
return 0;
}
