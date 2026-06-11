#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

string s,t;
unordered_map<char,set<ll>> mp;
int main(){
    cin>>s>>t;
    for(ll i=0;i<s.length();i++){
        mp[s[i]].insert(i);
    }
    ll ans=0;
    ll pre=-1;
    for(ll i=0;i<t.length();i++){
        set<ll>& st=mp[t[i]];
        if(st.size()==0){
            cout<<-1;return 0;
        }
        auto it=st.upper_bound(pre);
        if(it==st.end()){
            ans+=(s.length()-pre)+(*st.begin());
            pre=(*st.begin());
        }else{
            ans+=*it-pre;
            pre=*it;
        }
    }
    cout<<ans<<endl;

    return 0;
}