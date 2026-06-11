#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<ll> A(N);
    map<ll, ll> mmi;
    map<ll, ll> mpl;
    rep(i, N){
        cin >> A[i];
        int num = i+1;
        mmi[A[i] - num]++;
        mpl[A[i] + num]++; 
    }

    ll ans = 0;
    for(auto p : mmi){
        auto key = p.first;
        auto value = p.second;
        int pl = mpl[-key];
        ans += value * pl;
    }

    cout << ans << endl;


    return 0;
}