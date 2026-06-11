/*
hey stop, don't skip the shit till it's solved
*/
#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
int main()
{
int n;
cin>>n;
int a[n];
map<int,int> ps;
for(int i=0;i<n;i++)
{
cin>>a[i];
ps[a[i]]=i;
}
multiset<int> st;
ll ans=0;
st.insert(ps[n]);
for(int i=n-1;i>0;i--)
{
int a=0,b=0,c=0,d=0;
multiset<int>::iterator k=st.lower_bound(ps[i]);
if(k!=st.end())
{
c=(*k)+1;
k++;
if(k!=st.end())
{
d=(*k)+1;
}
k--;
}
if(k!=st.begin())
{
k--;
b=*k+1;
if(k!=st.begin())
{
k--;
a=*k+1;
}
}
if(a!=0 && b!=0 && c!=0 && d!=0)
{
ans+=(ll)(b-a)*(c-ps[i]-1)*i+(ll)(d-c)*(ps[i]+1-b)*i;
}
else if(a==0 && b!=0 && c!=0 && d!=0)
{
ans+=(ll)(c-ps[i]-1)*b*i+(ll)(d-c)*(ps[i]+1-b)*i;
}
else if(a!=0 && b!=0 && c!=0 && d==0)
{
ans+=(ll)(n+1-c)*(ps[i]+1-b)*i+(ll)(b-a)*(c-ps[i]-1)*i;
}
else if(a==0 && d==0 && b!=0 && c!=0)
{
ans+=(ll)(ps[i]+1-b)*(n+1-c)*i+(ll)b*(c-ps[i]-1)*i;
}
else if(a==0 && b==0)
{
if(d==0)
{
d=n+1;
}
ans+=(ll)(d-c)*(ps[i]+1)*i;
}
else if(c==0 && d==0)
{
ans+=(ll)(b-a)*(n-ps[i])*i;
}
st.insert(ps[i]);
}
cout<<ans<<endl;
}