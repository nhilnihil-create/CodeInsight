#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,a,b;
  cin >> n >> a >> b;
  if(a==0)
  {
    cout << "0";
    exit(0);
  }
  long long int sum=a+b,count=a*(n/sum);
  if(n%sum>a)
    count+=a;
  else
    count += n%sum;
  cout << count;
}