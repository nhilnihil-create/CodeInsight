#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;

int main() {

    vector<int> vec;

    int P,Q,R;

    cin >> P >> Q >> R;

    vec.emplace_back(P);
    vec.emplace_back(Q);
    vec.emplace_back(R);

    sort(vec.begin(),vec.end());

    cout << vec[0]+vec[1] << endl;

}