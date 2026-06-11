#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int n,l;
cin >> n >> l;
int sum1 = 0;
for(int i = 1; i <= n; i++){
  sum1 += l + i -1;
}
  
int ans;
  int t = 10000;
for(int i = 1; i <= n; i++){
  
  int sum2 = sum1 - (l + i - 1);
  int x = abs(sum2-sum1); 
  if(t >= x) ans = i;
  t = x;
}
cout << sum1 - (l + ans - 1) << endl;

}
  
