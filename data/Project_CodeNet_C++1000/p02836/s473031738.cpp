#include<iostream>
using namespace std;
int main()
{
string s;
cin>>s;
int n=s.length();
int cnt(0);
for(int i=0; i<n/2; ++i)
cnt+=(s[i]!=s[n-i-1]);
cout<<cnt;
}
