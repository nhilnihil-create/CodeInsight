#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int K, X;
    cin >> K >>X;
    for (int i = X - K + 1; i <= X + K - 1; i++)
    {
        cout << i;
        if (i != X + K -1)
        {
            cout << " ";
        }
        
    }
    cout << endl;

  return 0;
}
