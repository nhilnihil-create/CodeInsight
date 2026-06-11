#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<ll, ll> p;
 
#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < min(K, 41); i++) {
        vector<int> B(N);
        for(int j = 0; j < N; j++) {
            int l = max(0, j - A[j]);
            int r = j + A[j] + 1;
            B[l]++;
            if(r < N) B[r]--;
        }
        A[0] = B[0];
        for(int j = 1; j < N; j++) {
            B[j] += B[j - 1];
            A[j] = B[j];
        }
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}