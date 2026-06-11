#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
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
    map<ll,ll>mp;
    ll tmp = n;
    FOR(i,2,(ll)sqrt(n)+1){
        while(tmp%i==0){
            mp[i]++;
            tmp/=i;
        }
    }
    if(tmp!=1)mp[tmp]++;
    vector<ll>index(1001000);
    REP(i,1001000){
        index[i] = (ll)(i+1)*(i+2)/2;
    }
    ll answer = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        answer+=lower_bound(ALL(index),itr->second+1)-index.begin();
    }
    cout << answer << endl;
    return 0;
}