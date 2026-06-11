#include <bits/stdc++.h>
using namespace std;
int main(){
  double n;	cin >> n;
  vector<double>	a(n);
  for(int i=0;i<n;i++)	cin >> a[i];
  
  double ans=0;
  for(int i=0;i<n;i++){
    ans+=1/a[i];
  }
  printf("%.10f",1/ans);
}