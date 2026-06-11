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

int N;
ll K;
vector<ll> A, F;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    for(int i = 0; i < N; ++i){
        int a;
        cin >> a;
        A.push_back(a);
    }
    for(int i = 0; i < N; ++i){
        int f;
        cin >> f;
        F.push_back(f);
    }
    sort(A.begin(), A.end());
    sort(F.rbegin(), F.rend());
    ll lb = -1, ub = linf;
    while(ub - lb > 1){
        ll mid = (ub + lb) / 2;
        ll cnt = 0;
        for(int i = 0; i < N; ++i){
            ll d = mid / F[i];
            cnt += max(A[i] - d, 0LL);
        }
        if(cnt > K) lb = mid;
        else ub = mid;
    }
    cout << ub << endl;
    return 0;
}