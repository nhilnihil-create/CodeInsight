#include<iostream>

using namespace std;

void test_case()
{
string s,t;
cin>>s;
cin>>t;
int n=3,ans=0;
for(int i=0;i<n;++i)
{
if(s[i]==t[i])
{
ans++;
}
else
continue;
}
cout<<ans<<"\n";
}
int main()
{
test_case();
return 0;
}