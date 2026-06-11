#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
  int n;cin>>n;
  int kitna=(int)ceil(n*1.0/1000);
  int left=(kitna*1000)-n;
  cout<<left<<endl;
}