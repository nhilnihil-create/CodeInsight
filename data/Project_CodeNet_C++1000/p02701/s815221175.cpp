#include<bits/stdc++.h>
using namespace std;
int main()
{
 	int n;
  cin>>n;
  set<string>s;
  while(n--)
  {
   	string p;
    cin>>p;
    s.insert(p);
  }
  cout<<int(s.size());
}