#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    int h1,m1,h2,m2,k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    cout << max(0,h2*60+m2-h1*60-m1-k) << endl;

}
