#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n;
cin >> n;
vector<int> a(n);
for(int i = 0; i< n;i++)cin >> a[i];
double ans = 0.0;
for(int i = 0; i< n;i++)ans += (double)(1.0 / a[i]);
ans =  (double)(1.0 / ans);
printf("%.10f\n",ans);
return 0;
}