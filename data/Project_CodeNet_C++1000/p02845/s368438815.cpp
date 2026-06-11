#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll ZERO = 0;
const int Inf = 1000000000;
const ll INF= 1e18;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<int> cnt(N);
    ll ret = 1;
    int cnt2 = 3;
    for(int i = 0;i < N;i++) {
        if(vec.at(i) == 0) {
            ret = ret * cnt2 % MOD;
            cnt2--;
        }
        else {
            ret = ret * (cnt.at(vec.at(i) - 1) - cnt.at(vec.at(i))) % MOD;
        }
        cnt.at(vec.at(i))++;
    }
    cout << ret << endl;
}