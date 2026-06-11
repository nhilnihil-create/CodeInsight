#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n;
string s="";
void dfs(string s,char mx)
{
    if(s.length()==n)
     cout<<s<<"\n";
     else
     {
         for(char c='a';c<=mx;c++)
         { //s+=c;
            if(c==mx)
             dfs(s+c,mx+1);
             else
              dfs(s+c,mx);
         }
     }
}

int main()
{ 
  cin>>n;
  if(n==1)
  {
      cout<<'a';
      return 0;
  }
  dfs("",'a');
return 0;
}
