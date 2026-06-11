#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    for (int i = 0; i < S.length() - 1; i++)
    {
        if (S[i] == S[i + 1])
        {
            cout << "Bad" << endl;
            return 0;
        }
        
    }
    cout << "Good" << endl;
  return 0;
}
