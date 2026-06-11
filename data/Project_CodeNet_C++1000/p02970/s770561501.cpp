#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(){

int N, D;
cin >> N >> D;

double ans;
ans = D * 2 + 1;
ans =ceil(N / ans);

cout << ans << endl;

return 0;
}