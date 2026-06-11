#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,k;
  cin >> n >> k;
vector<long int> a(n);
  long int max,sum;
  sum=0;
  for(int i=0;i<n;++i)
  {
  cin >> a.at(i);
  a[i]=(a[i]+1);
    if(i<k) sum=sum+a.at(i);
  }
  max=sum;
  
  for(int i=0;i<n-k;++i)
  {
  sum=sum-a.at(i)+a.at(i+k);
  if(sum > max) max=sum;
  }
  if(max%2==0) cout << max/2;
  else cout << (max/2) << ".5";
return 0;}