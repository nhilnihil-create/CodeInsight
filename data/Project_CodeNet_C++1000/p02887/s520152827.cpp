#include<bits/stdc++.h>
#define ll long long int
using namespace std;
//ALLAH is one
int main()
{
    ll n,i,j,cnt=1;
   string s;
   char ch;
   s.clear();
   cin>>n>>s;
   for(i=0;i<n-1;i++)
   {
    if(s[i]!=s[i+1])
        cnt++;
   }
cout<<cnt<<endl;
    return 0;
}

