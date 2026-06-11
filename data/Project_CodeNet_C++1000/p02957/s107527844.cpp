#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    double n,a,b; cin >> a >> b;
    n = (a+b)/2.0;
    if(floor(n)==ceil(n))
    printf("%.0lf\n",n);
    else
    printf("IMPOSSIBLE\n");
    return 0;   
}