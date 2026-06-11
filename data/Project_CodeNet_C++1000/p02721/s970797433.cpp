#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<queue>
#include<stack>
#include<cctype>
#include<cstring>
#include<list>
#include<map>
#include<sstream>
#include<set>
#include<string>
#include<vector>
typedef long long ll;
using namespace std;
#define MN 300005
#define MM 600005
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define RF(i,a,b) for(int i=a;i>=(b);--i)
#define fast  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define int long long
signed main()
{
   int n,k,c;
   string s;
   cin>>n>>k>>c>>s;
   int a[n],b[n];
   for(int i=0,x=0;i<n;i++){
       if(s[i]=='o'){
           a[x++]=i;
           i+=c;
       }
   }
   for(int i=n-1,x=k-1;i>=0&&x>=0;i--){
       if(s[i]=='o'){
           b[x--]=i;
           i-=c;
       }
   }
   for(int i=0;i<k;i++)if(a[i]==b[i])cout<<a[i]+1<<endl;
   return 0;
}
