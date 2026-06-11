#include<bits/stdc++.h>
using namespace std;
set<char>s;
map<char,int>mp;
long long int a[3000000];
int main(){

 long long int n,k,m,i,c=1,x,y,z  ;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    x=a[1];
    for(i=2;i<=n;i++)
    {
        if(a[i]<=x)
        {
            c++;
        }
         x=min(x,a[i]);
    }
    cout<<c;
   return 0;

}