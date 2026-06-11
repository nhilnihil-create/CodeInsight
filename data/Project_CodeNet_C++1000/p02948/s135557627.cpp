#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int N, M;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    vector<pii> work;
    set<int> days;
    for(int i = 0; i <= M; ++i) days.insert(i);
    for(int i = 0; i < N; ++i){
        int A, B;
        cin >> A >> B;
        work.push_back({B, M - A});
    }
    sort(work.rbegin(), work.rend());
    int ans = 0;
    for(auto u : work){
        int val = u.first;
        int ub = u.second;
        auto it = days.upper_bound(ub);
        if(it !=days.begin() && !days.empty()){
            --it;
            days.erase(it);
            ans += val;
        }
    }
    cout << ans << endl;
    return 0;
}