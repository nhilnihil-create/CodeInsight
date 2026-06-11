#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL<<60;
#define all(x) (x).begin(),(x).end()
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int main() {
    int N; cin >> N;
    map<string,int> mp;
    int sum = 0;
    REP(i,N) {
        string s; int a;
        cin >> s >> a;
        sum += a;
        mp[s] = sum;
    }
    for(auto &p:mp) {
        p.second = sum - p.second;
    }
    string t; cin >> t;
    cout << mp[t] << endl;
}