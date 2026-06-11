#include <bits/stdc++.h>
using namespace std;
int main()
{
long long i,j,k,a,b,c=0,d=0,n,m,t;
cin>>n;
vector<string>A(n);
vector<int>B(n);
string s;
for(i=0;i<n;i++)
  cin>>A[i]>>B[i];
cin>>s;
for(i=n-1;i>=0;i--)
{
  if(A[i]==s) break;
  else d+=B[i];
}
cout<<d<<endl;
return 0;
}
