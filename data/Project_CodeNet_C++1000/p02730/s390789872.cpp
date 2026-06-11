#include <bits/stdc++.h>
using namespace std;

int main() {
string S;
cin >> S;
string a, b;
int L =S.size();
a = S.substr(0, (L-1)/2);
b = S.substr((L+3)/2-1, (L-1)/2);
string sinv=S, ainv=a, binv=b;
reverse(S.begin(), S.end());
reverse(a.begin(), a.end());
reverse(b.begin(), b.end());
if(a==ainv && S==sinv && b == binv) cout << "Yes" << endl;
else cout << "No" << endl;
  return 0;
}
