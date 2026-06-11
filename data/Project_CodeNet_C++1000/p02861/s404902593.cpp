#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
int n,a = 1;
cin >> n;
vector<pair<double,double>> x(n);
rep(i,n) {
  cin >> x.at(i).first >> x.at(i).second;
}
for (int i = n;i > 0;i--) a *= i;
double ans = 0;
rep(i,a) {
rep(i,n-1) {
  double cnt;
  cnt = pow(x.at(i).first-x.at(i+1).first,2) + pow(x.at(i).second-x.at(i+1).second,2);
  ans += sqrt(cnt);
}
next_permutation(x.begin(),x.end());

}
ans /= a;
printf("%.10f\n",ans);
return 0;
}

