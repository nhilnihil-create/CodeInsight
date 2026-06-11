#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    ll n;
    cin >> n;
    vector<pair<ll,ll> > a(n);
    map<pair<ll,ll>,ll> m;
    REP(i,n){
        cin>>a[i].first >> a[i].second;
    }
    
    REP(i,n){
        REP(j,n){
            if(i!=j)
                m[make_pair(a[i].first-a[j].first,a[i].second-a[j].second)]++;
        }
    }
    ll max_num = 0;
    for(auto itr = m.begin(); itr != m.end(); ++itr) {
        max_num = max(max_num,itr->second);
    }

    cout << n-max_num << endl;
    return 0;
}