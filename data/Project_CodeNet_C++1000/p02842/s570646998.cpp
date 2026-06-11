#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N = 0;
    cin >> N;
    if (N == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    
    for (size_t i = 0; i < N/10*9; i++)
    {
        if((N - i)*108/100 == N){
            cout << N - i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
    

    return 0;
}