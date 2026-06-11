#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
 int i,n,s;
 s=0;
 cin >> n;
 int a[n],b[n],c[n-1];
 for(i=0;i<n;i++)
 cin >> a[i];
 for(i=0;i<n;i++)
 {
  cin >> b[i];
  s+=b[i];
 }
 for(i=0;i<(n-1);i++)
 cin >> c[i];
 for(i=1;i<n;i++)
 {
  if(a[i]==(a[i-1]+1))
  s+=c[a[i-1]-1];
 }
 cout << s;
 return 0;
}