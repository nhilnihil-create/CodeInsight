#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
 
  while(1){
    int in; cin >> in ;
    if(in==0) break;
     double n = (double)in;
     double s[in]={}, sum=0.0;
    for(int i=0;i<n;i++){
      cin >> s[i];
      sum += s[i];
    }
     double ans=0.0, m = sum / n;
    for(int i=0; i<n; i++){
      ans += (s[i] - m)*(s[i] - m);
      //      cout << ans << " " << n << "\n";
    }
    printf("%.10lf\n",sqrt(ans/n));
  }
}