#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
int n;
cin >> n;
vector<double> v(n);
rep(i,n) cin >> v.at(i);
sort(v.begin(),v.end());
reverse(v.begin(),v.end());
double ans = 0;
for(int i = 0; i < n-1; i++){
  ans += v.at(i)/pow(2,i+1);
}
ans += v.back()/pow(2,n-1);
  
cout << ans << endl;

}
