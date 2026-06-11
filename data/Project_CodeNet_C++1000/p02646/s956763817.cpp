#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long a,b,v,w,t;
  cin>>a>>v>>b>>w>>t;
  cout<<(t*(abs(v)-abs(w))<abs(a-b)?"NO":"YES");
}
