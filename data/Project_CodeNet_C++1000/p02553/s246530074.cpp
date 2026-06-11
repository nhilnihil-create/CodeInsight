#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long s1=a*c,s2=a*d,s3=b*c,s4=b*d;
  long long sum=max(s4,max(s3,max(s2,s1)));
  cout<<sum;
}