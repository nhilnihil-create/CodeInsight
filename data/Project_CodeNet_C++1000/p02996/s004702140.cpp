#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;

int main(){
    int N; cin >> N;
    vector<pair<int, int>> p(N);
    rep(i, N){
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(b, a);
    }
    sort(all(p));
    ll time = 0;
    rep(i, N){
        time += p[i].second;
        if(time > p[i].first){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}