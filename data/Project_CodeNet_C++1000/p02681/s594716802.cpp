#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const int N=200000;

void Run()
{
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int a[N],b[N];
list<char>v;
map<char,int>mp;
int main()
{
   Run();
   string s,t;
   cin>>s>>t;
   int f=0;
   for(int i=0;i<s.size();i++)
   {
       if(s[i]==t[i])
        f=1;
       else
       {
           f=0;
           break;
       }
   }
   if(f==1)
    cout<<"Yes";
   else
    cout<<"No";
}

