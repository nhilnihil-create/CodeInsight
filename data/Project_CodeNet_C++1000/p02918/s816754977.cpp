#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 100000;
ll mod = INF;

int n,k;
int cnt=0;
int ans=0;
string s;

int main(){
    cin >> n>>k;
    cin >> s;

    rep(i,s.size()-1){
        if(s[i]==s[i+1])ans++;
    }

    if(s[0]=='R')s='L'+s;
    else s='R'+s;

    if(s[(int)s.size()-1]=='R')s=s+'L';
    else s=s+'R';

    rep(i,s.size()-1){
        if(s[i]!=s[i+1])cnt++;
    }

    while(cnt>1&&k>0){
        ans+=2;
        cnt-=2;
        k--;
    }

    if(cnt==0){
        ans-=2;
    }else if(cnt==1){
        ans-=1;
    }

    cout << ans<<endl;

    return 0;
}
