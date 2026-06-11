#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  int n;
  cin>>n;
  cout<<(n%2==0 ?n/2-1:(n+1)/2-1)<<endl;
}