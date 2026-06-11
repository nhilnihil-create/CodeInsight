#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    int n, d;
    cin >> n >> d;
    int a = 2*d + 1;
    if(n%a != 0) cout << n/a + 1 << endl;
    else cout << n/a << endl;
    return 0;
}