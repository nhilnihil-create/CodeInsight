#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll ZERO = 0;
const ll INF = 1e14;
const ll MOD = 1000000007;
const double PI = 3.1415926535897;

int main() {
    int N;
    cin >> N;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        int A, B;
        cin >> A >> B;
        vec.at(i) = P(A, B);
    }
    sort(vec.begin(), vec.end());
    map<P, int> ma;
    for(int i = 0;i < N - 1;i++) {
        for(int j = i + 1;j < N;j++) {
            int A = vec[j].first - vec[i].first;
            int B = vec[j].second - vec[i].second;
            ma[P(A, B)]++;
        }
    }
    int ret = 0;
    for(auto x:ma) {
        ret = max(ret, x.second);
    }
    cout << N - ret << endl;
}