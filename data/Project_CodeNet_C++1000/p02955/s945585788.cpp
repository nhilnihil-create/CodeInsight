#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using ll = long long;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
}

void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for(ll i = 1; i * i <= n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(),ret.end());
    return (ret);
}

int main() {
    ll N,K;
    cin >> N >> K;
    auto A = InputVec(N);
    ll sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
    }
    auto divs = divisor(sum);
    ll M = divs.size();
    for (int i = 0; i < M; ++i) {
        ll currentDiv = divs[M-1-i];
        //cout << currentDiv << endl;
        vector<ll> v;
        vector<ll> SS;
        for (int j = 0; j < N; ++j) {
            v.push_back(A[j] % currentDiv);
        }
        sort(v.begin(),v.end());
        SS.push_back(0);
        for (int k = 0; k < N; ++k) {
            SS.push_back(SS.back() + v[k]);
        }
        for (int k = 0; k < N; ++k) {
            ll A =SS[k];
            ll B = (N-k)*1ll*currentDiv-(SS[N]-SS[k]);
            if(max(A,B) <= K){
                cout << currentDiv << endl;
                return 0;
            }
        }

    }


}
