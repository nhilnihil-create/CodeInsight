#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int p,q,r;
    cin >> p >> q >> r;
    cout << p + q + r - max(p,max(q,r)) << endl;
}
