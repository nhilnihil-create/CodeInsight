#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;

    for (int i = 0; i < S.size(); i++)
    {
        if ((i % 2 == 0 && S[i] == 'L') || (i % 2 != 0 && S[i] == 'R'))
        {
            cout << "No" << endl;
            return 0;
        }
        
    }
    cout << "Yes" << endl;    
  return 0;
}
