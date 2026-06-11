#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, pair<int, int> > p;
 
#define MOD 1000000007

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    if(N % 2) {
        cout << B[N / 2] - A[N / 2] + 1 << endl;
    } else {
        int a = A[N / 2] + A[N / 2 - 1];
        int b = B[N / 2] + B[N / 2 - 1];
        cout << (b - a) + 1 << endl;
    }
}