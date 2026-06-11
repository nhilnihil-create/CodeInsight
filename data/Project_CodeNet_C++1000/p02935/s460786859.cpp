#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
int n;
cin >> n;
vector<double> v(n);
for(int i = 0; i< n;i++)cin >> v[i];
sort(v.begin(), v.end());
double a;
for(int i = 0; i< n-1 ;i++){
    a = (double)((v[i] + v[i+1])*0.5);
     v[i+1]  = a;
}
printf("%.10f\n", a);
return 0;
}