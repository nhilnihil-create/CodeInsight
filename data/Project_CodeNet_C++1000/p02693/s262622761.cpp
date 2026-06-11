#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,n) for(int i=1; i<n; i++)
using vi = vector<int>;

int main(){
    int k, a, b;
    cin >> k >> a >> b;
    if (a % k == 0)cout << "OK" << '\n';
    else if (b % k == 0)cout << "OK" << '\n';
    else if(a / k != b / k)cout << "OK" << '\n';
    else cout << "NG" << '\n';
    return 0;
}