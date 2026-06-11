#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() { 
    ll K, N;
    cin >> K >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<ll> dis;
    for (int i = 1; i < N; i++){
      dis.push_back(A[i] - A[i - 1]);
    }
    dis.push_back(K-A[N - 1] + A[0]);
    sort(dis.begin(), dis.end());
    ll out = 0;
    for (int i = 0; i < N - 1; i++) out += dis[i];
    cout << out << endl;
    return 0;
}