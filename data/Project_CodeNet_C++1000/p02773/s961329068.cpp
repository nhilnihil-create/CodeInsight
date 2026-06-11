#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    map<string, int> mp;
    REP(i, N){
        cin >> S[i];
        mp[S[i]] += 1;
    }

    int res = 0;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        res = max(res, itr->second);
    }

    vector<string> ans;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        string s;
        if (itr->second == res){
            cout << itr->first << endl;
        }
    }
}