#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N,M,V,P;
    cin >> N >> M >> V >> P;
    vector<ll> A(N);
    vector<ll> B(N + 1);
    B[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(),A.end(),greater<ll>());
    for(int i = 0; i < N; i++){
        B[i + 1] = B[i] + A[i];
        //cout << A[i] << "," << B[i + 1] << endl;
    }
    ll count = 0;
    ll thr = A[P - 1];
    for (int i = 0; i < N; ++i) {
        if(i < P){
            count++;
            continue;
        }
        if(A[P - 1] > A[i] + M){
            continue;
        }
        ll votable = 0;
        votable += (P - 1) * M;
        votable += (N - i) * M;
        votable += (i - P + 1) * (A[i] + M) - (B[i]-B[P - 1]);
        if(votable >= M * V){
            count++;
        }
    }
    cout << count << endl;
}
