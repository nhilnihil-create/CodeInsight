#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    if (count(A.begin(), A.end(), 0) > 0) {
        cout << 0 << endl;
        return 0;
    }

    ll prod = 1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > 1000000000000000000LL / prod) {
            cout << -1 << endl;
            return 0;
        }
        prod *= A[i];
    }
    
    cout << prod << endl;
    return 0;
}
