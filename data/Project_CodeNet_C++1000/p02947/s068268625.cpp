#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long n,a=0,i;
  string s;
  cin>>n;
  map<string,long long>m;
  for(i=0;i<n;i++)
  {
    cin>>s;
    sort(s.begin(),s.end());
    a+=m[s];
    m[s]++;

  }
  cout<<a<<endl;

}
