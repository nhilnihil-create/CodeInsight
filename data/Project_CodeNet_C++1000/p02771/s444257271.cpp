#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if ((A == B && A != C) || (A == C && A != B) || (B == C && B != A))
    {
        cout << "Yes" << endl;
    } else
    {
        cout << "No" << endl;
    }
    
    
    
  return 0;
}
