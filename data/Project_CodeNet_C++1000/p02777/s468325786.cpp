#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main() {
    int a,b;
    string s,t,u;
    cin >> s >> t >> a >> b >> u;
    if(u==s) a--;
    if(u==t) b--;
    cout << a << " " << b << endl;
}