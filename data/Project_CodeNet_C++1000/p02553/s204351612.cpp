#include <iostream>
#include <cmath>
#include<algorithm>
#include <string>
#include<iomanip>
#include <string.h>
#include<stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    long long a = 0, b = 0 , c = 0 , d = 0;
    cin >> a >> b >> c >> d;
    long long mx1 = a*c;
    long long mx2 = a*d;
    long long mx3 = b*c;
    long long mx4 = b*d;
    long long ans = max(max(mx1,mx2),max(mx3,mx4));
    cout << ans;
return 0;
}
