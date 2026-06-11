#include<bits/stdc++.h>
using namespace std;
string nw(string s)
{
  	int f=0;
    int len=s.length();
    int j=s.length()-1;
    while((s[j]=='9' || s[j]==(s[j-1]+1)) && j!=0)
    {
      s.pop_back();
      j--;
    }
    int n=s.length();
  	if(s[0]=='9' && n==1)
    {
      s[0]='1';
      f=1;
    }
    else s[n-1]++;
    while(n!=len)
    {
      char c=max((int)'0',s[n-1]-1);
      s.push_back(c);
      n++;
    }
  if(f)s.push_back('0');
  return s;
}
int main()
{
  vector<string>a(100001);
  string cur;
  cur+="10";
  for(int i=1;i<100001;i++)
  {
    if(i<10)
    {
      string c;
      c.push_back(i+'0');
      a[i]=c;
      continue;
    }
    a[i]=cur;
    cur=nw(cur);
  }
  int k;
  cin>>k;
  cout<<a[k];

 // for(int i=100;i<=500;i++)cout<<a[i]<<endl;
   return 0;
  }