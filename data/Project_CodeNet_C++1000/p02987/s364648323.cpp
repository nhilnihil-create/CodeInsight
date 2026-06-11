#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string S;
    cin >> S;
    map<char, int> t;
    for (int i = 0; i < S.length(); i++)
    {
        t[S[i]]++;
    }
    if (t.size() == 2 && t[S[0]] == 2)
    {
        cout << "Yes" << endl;
    } else
    {
        cout << "No" << endl;
    }
    
    

  return 0;
}
