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

struct BIT{
    int N;
    vector<int> bit;

    BIT(int n = 0){
        N = n;
        bit.resize(n + 1);
    }

    int sum(int i){
        int s = 0;
        while(i > 0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, int x){
        while(i <= N){
            bit[i] += x;
            i += i & -i; 
        }
    }

    int ser_sum(int val){
        int lb = -1, ub = N + 1;
        while(ub - lb > 1){
            int mid = (ub + lb) / 2;
            if(sum(mid) >= val) ub = mid;
            else lb = mid;
        }
        return ub;
    }
};

int N;
ll res = 0;
int P[100010];
vector<pii> ps;//val, idx
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> P[i];
        ps.push_back({P[i], i + 1});
    }
    sort(ps.rbegin(), ps.rend());
    BIT bit(N);
    for(int i = 0; i < N; i++){
        ll val = ps[i].first;
        ll idx = ps[i].second;
        bit.add(idx, 1);
        int s1 = bit.sum(idx);
        ll r1 = bit.ser_sum(s1 + 1);
        ll r2 = bit.ser_sum(s1 + 2);
        ll l1 = bit.ser_sum(s1 - 1);
        ll l2 = bit.ser_sum(s1 - 2);
        res += val * ((r2 - r1) * (idx - l1) + (l1 - l2) * (r1 - idx));
    }
    cout << res << endl;
    return 0;
}