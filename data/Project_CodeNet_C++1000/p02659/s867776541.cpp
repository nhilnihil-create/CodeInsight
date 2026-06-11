#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < n; i++)
#define rep2(i,x,n) for (int i = x; i < n; i++)
using ll = long long int;
int main() {
    ll A; cin >> A;
    string B; cin >> B;
    ll hunB = (B[0]-'0')*100 + (B[2]-'0')*10 + (B[3]-'0');
    A = A*hunB/100;
    cout << A << endl;
    return 0;
}