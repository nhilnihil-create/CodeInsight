#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N, X;
    cin >> N >> X;
    int L[N];
    for (int i = 0; i < N; i++)
    {
        L[i] = 0;
        cin >> L[i];
    }
    
    int D = 0;
    for (int i = 0; i < N; i++)
    {
        D += L[i];
        if (D > X)
        {
            cout << i + 1 << endl;
            return 0;
        }
        
    }
    cout << N + 1 << endl;

  return 0;
}
