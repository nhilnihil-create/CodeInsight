#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    string s;
    cin>>s;
    int ans=0;
    rep(i,s.size()){
        if(i!=s.size()-1 && s[i]==s[i+1]){
            if(i!=s.size()-2) ans++;
            i+=2;
        }
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}