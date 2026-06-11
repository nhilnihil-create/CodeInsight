#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    ll a, b, k;
    cin >> a >> b >> k;
    ll zero = 0;
    if(a >= k){cout << a-k << " " << b << endl; return 0;}
    else {cout << 0 << " " << max(zero, b-(k-a)) << endl; return 0;}
}
