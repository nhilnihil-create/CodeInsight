#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int max_A = 0, nmax_A = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (A[i] > max_A)
        {
            max_A = A[i];
        }
        else if (A[i] == max_A)
        {
            nmax_A = A[i];
        }
        else if (A[i] > nmax_A)
        {
            nmax_A = A[i];
        }
        
        
        
    }
    
    for (int i = 0; i < N; i++)
    {
        if (A[i] == max_A)
        {
            cout << nmax_A << endl;
        }
        else
        {
            cout << max_A << endl;
        }
    }
    
}

int main() {
    solve();
    return 0;
}