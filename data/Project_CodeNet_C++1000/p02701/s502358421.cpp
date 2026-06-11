#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
ll n;
  cin>>n;
  set<string> s;
  while(n--)
  {
     string str;
    cin>>str;
    s.insert(str);
  }
  cout<<s.size()<<endl;
}