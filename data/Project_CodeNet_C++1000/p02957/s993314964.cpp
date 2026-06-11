#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int A, B;
    cin >> A >> B;
    if (abs(A - B) % 2 == 0)
    {
        cout << min(A, B) + abs(A - B) / 2 << endl;
    } else
    {
        cout << "IMPOSSIBLE" << endl;
    }
    
    

  return 0;
}
