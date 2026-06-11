#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char findans(int k)
{
  char aaa[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  return aaa[k-1];
}
int main()
{
  long long int n; 
  cin>>n;
  string s;
  if(n<=26)
  cout<<findans(n)<<endl;
  else
  {
    while(n>0)
    {
      n--;
      char ans='a'+(char)(n%26);
      s+=ans;
    //  cout<<ans;
      n=n/26;
    }
    //if(n>0)
   // s+=findans(n);
 
    for(int i=s.length()-1;i>=0;i--)
    cout<<s[i];
    cout<<endl;
  }
}