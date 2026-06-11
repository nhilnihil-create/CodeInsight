#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool ispal(string a)
{
    long long int n=a.length();
    if(n==1)
        return true;
    else{
    int i=0,j;
    j=n-1;
    while(1)
    {
        if(a[i]!=a[j])
        {
            cout<<i<<" "<<j;
           return false;
        }
        i++,j--;
        if(i==j)
         {
        //     cout<<i<<" ";
             break;
        }
    }
    return true;
}}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 ll n;
 cin>>n;
 map<string,int>m;
 for(int i=0;i<n;i++)
 {
     string a;
     cin>>a;
     m[a]++;
 }
 int ma=0;
 for(auto x:m)
 {
     if(x.second>ma)
     {
         ma=x.second;
     }
 }
 //cout<<ma<<"\n";
 for(auto x:m)
 {
     if(x.second==ma)
     {
         cout<<x.first<<endl;
     }
 }
}

