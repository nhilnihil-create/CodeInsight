#include <bits/stdc++.h>
#include<math.h>
using namespace std;
using ll = long long;

int main(){ 
    int n;
    cin >> n;
    double ans;
    if(n%2==0)  ans = 0.5;
    else  ans = (double)((n+1)*0.5 / n);
   printf("%.10f\n",ans);
   return 0;
}