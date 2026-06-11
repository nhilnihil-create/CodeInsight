#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l[2005][2005];
ll r[2005][2005];
ll u[2005][2005];
ll d[2005][2005];
string s[2005];

int main(){
    ll h,w;
    cin >> h >> w;
    for(ll i=0;i<h;i++){
        cin >> s[i];
    }
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            if(s[i][j]=='#') l[i][j]=0;
            else if(s[i][j]=='.'&&j==0) l[i][j]++;
            else l[i][j]=l[i][j-1]+1;
        }
        for(ll j=w-1;j>=0;j--){
            if(s[i][j]=='#') r[i][j]=0;
            else if(s[i][j]=='.'&&j==w-1) r[i][j]++;
            else r[i][j]=r[i][j+1]+1;
        }        
    }
    for(ll i=0;i<w;i++){
        for(ll j=0;j<h;j++){
            if(s[j][i]=='#') d[j][i]=0;
            else if(s[j][i]=='.'&&j==0) d[j][i]++;
            else d[j][i]=d[j-1][i]+1;
        }
        for(ll j=h-1;j>=0;j--){
            if(s[j][i]=='#') u[j][i]=0;
            else if(s[j][i]=='.'&&j==h-1) u[j][i]++;
            else u[j][i]=u[j+1][i]+1;
        }
    }
    ll res=0;
    for(ll i=0;i<h;i++){
        for(ll j=0;j<w;j++){
            res=max(res,r[i][j]+l[i][j]+u[i][j]+d[i][j]-3);
        }
    }
    cout << res << endl;
}
