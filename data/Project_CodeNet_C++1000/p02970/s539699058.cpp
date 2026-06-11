#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{   
  int n,d;
  cin>>n>>d;
  d=d+d+1;
  int ans=(n+d-1)/d;
  cout<<ans;
}