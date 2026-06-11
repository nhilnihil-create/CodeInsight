#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,j,k,c=1,x=1,t;
   cin>>n;
   string s;
   while(n!=0)
   {
             t=n%26;
             n--;
             //cout<<t<<endl;
             if(t==0)
                    s+='z';
             else
             {
                       s+=char(96+t);
             }
             n/=26;
   }
   reverse(s.begin(),s.end());
   cout<<s;
}
