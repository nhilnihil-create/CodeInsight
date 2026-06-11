#include<bits/stdc++.h>
#include<limits>
#define ll long long
#define F first
#define S second
#define pb push_back
#define oo (1LL<<63-1)
#define endl '\n'
#define si size()
#define all(v) v.begin(),v.end()
#define FASTIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define Matrix vector< vector < long long > >

using namespace std;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

const long double Pi=acos(-1),e=2.718;
const int N=2e5+10, mod=1e9+7;
string s,t;
vector<ll> occ[26];
int main ()
{
    FASTIO
    cin >> s >> t;
    for(int i=0;i<s.si;i++)occ[s[i]-'a'].pb(i);
    ll last=-1,ans=0;
    for(int i=0;i<t.si;i++){
        if(occ[t[i]-'a'].si==0)return cout << -1 << endl,0;
        auto it=upper_bound(all(occ[t[i]-'a']),last);
        if(it==occ[t[i]-'a'].end()){
//            cout << "#1 " << s.si-last-1 << endl;
            ans += s.si-last-1;
            last = -1;
            i--;
        }
        else{
//            cout << "#2 " << *it-last << endl;
            ans += *it-last;
            last = *it;
        }
    }
    cout << ans << endl;
    return 0;
}
/**

*/
