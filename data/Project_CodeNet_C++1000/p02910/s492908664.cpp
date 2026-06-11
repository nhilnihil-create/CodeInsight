#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ii=pair<ll,ll>;
using vi=vector<ll>;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF (ll)1e18
#define all(x) (x).begin(),(x).end()
#define print(a); for(auto x:a)cout<<x<<" "; cout<<"\n";
#define mset(a); memset(a,0,sizeof(a));

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
    string s;cin>>s;bool state=1;
    for(int i=0;i<s.size();i++){
        if(i&1&&s[i]=='R')state=0;
        if(i%2==0&&s[i]=='L')state=0;
    }
    if(state)cout<<"Yes\n";
    else cout<<"No\n";
}
