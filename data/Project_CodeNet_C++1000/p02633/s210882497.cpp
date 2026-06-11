#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int x;
    cin >> x;
    int a=360*x/__gcd(x,360);
    cout << a/x << endl;

}
