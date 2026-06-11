#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using P = pair<int, int>;
int main()
{
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    if(ceil(a/d) >=ceil(c/b)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}