#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    int now = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        v.push_back({b,a});
    }
    sort(v.begin(),v.end());
    for(auto u : v){
        if(now + u.second > u.first){
            cout << "No" << endl;
            return 0;
        }
        now += u.second;
    }
    cout << "Yes" << endl;
    return 0;
}