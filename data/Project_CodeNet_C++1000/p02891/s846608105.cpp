#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  int k=0;
  long long n;
  cin>>n;
  long long count=0,a=0,b=0;
  
  while(s[0]==s[k++] && k<=s.length() && s[0]==s[s.length()-1])a++;
  k=s.length()-1;
  while(s[s.length()-1]==s[k--] && k>=0 &&s[0]==s[s.length()-1])b++;
  if(a==s.length())
  {
    cout<<n*a/2<<endl;
    return 0;
  }
  
    for(int i=a;i<s.length()-b;i++)
    {
		if(s[i]==s[i-1])
        {
          count++;
          i++;
        }
    }
  //cout<<a<<' '<<b<<' '<<count<<endl;
  long long sum=(a/2)+(b/2)+(n-1)*((a+b)/2)+n*(count);
  cout<<sum<<endl;
  return 0;
}