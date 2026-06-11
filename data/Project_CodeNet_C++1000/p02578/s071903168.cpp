#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n;
 cin>>n;
 long long a[n];
 for(int i=0;i<n;i++)
 {
     cin>>a[i];
 }
 long long cnt=0;
 long long m=0;
 for(int i=0;i<n;i++)
 {
  m = max(m,a[i]);
  int b= m;
  cnt +=b-a[i];

 }
 cout<<cnt;
    return 0;
}
