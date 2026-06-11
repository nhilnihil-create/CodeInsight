#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n;
cin >> n;
vector<int> w(n);
vector<int> a;
rep(i,n) cin >> w.at(i);

for(int t = 1; t <= n; t++){
  int sum1 = 0,sum2 = 0;
  for(int i = 1; i <= n; i++){
    if(i <= t) sum1 += w.at(i-1);
    else sum2 += w.at(i-1);
  }
  a.push_back(abs(sum2-sum1));
}
sort(a.begin(),a.end());
cout << a.at(0) << endl;
}
  
