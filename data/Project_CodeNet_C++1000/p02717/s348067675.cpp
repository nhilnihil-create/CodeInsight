#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
 // freopen("input.txt","r",stdin);
#endif

  int a,b,c;
  cin>>a>>b>>c;
  swap(a,b);
  swap(a,c);
  cout<<a<<" "<<b<<" "<<c<<endl;
  return 0;
}