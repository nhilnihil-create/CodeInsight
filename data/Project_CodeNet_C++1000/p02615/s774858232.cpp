#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<ll>a(n);
  for(int i=0;i<n;i++)
    cin>>a[i];
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  ll s=0;
  for(int i=1;i<n;i++)
    s+=a[i/2];
  cout<<s;
  return 0;
}

  