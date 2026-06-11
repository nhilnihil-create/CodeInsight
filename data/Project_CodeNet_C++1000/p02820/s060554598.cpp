#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int main()
{
  ll n,k,r,s,p;
  cin>>n>>k>>r>>s>>p;
  string sp;
  cin>>sp;

  string q="";
  ll pro=0;

  for(int i=0;i<n;i++)
  {
      if(i-k<0)
      {
          if(sp[i]=='r')
          {
              q+="p";
              pro+=p;
          }
          else if(sp[i]=='s')
          {
              q+="r";
              pro+=r;
          }
          else
          {
              q+="s";
              pro+=s;
          }
      }
      else
      {
           if(sp[i]=='r')
          {
             if(q[i-k]!='p')
             {
                 q+="p";
                 pro+=p;
             }
             else
             {
                 if(i+k<n)
                 {
                     if(sp[i+k]=='s')
                        q+="s";
                     else
                        q+="r";
                 }
                 else
                    q+="p";
             }
          }
          else if(sp[i]=='s')
          {
             if(q[i-k]!='r')
             {
              q+="r";
              pro+=r;
             }
             else
             {
                 if(i+k<n)
                 {
                     if(sp[i+k]=='r')
                        q+="s";
                    else
                        q+="p";
                 }
                 else
                    q+="p";
             }
          }
          else
          {
             if(q[i-k]!='s')
             {
              q+="s";
              pro+=s;
             }
             else
             {
                 if(i+k<n)
                 {
                     if(sp[i+k]=='s')
                        q+="p";
                     else
                         q+="r";
                 }
                 else
                    q+="r";
             }
          }
      }
  }
  cout<<pro<<"\n";
return 0;
}
