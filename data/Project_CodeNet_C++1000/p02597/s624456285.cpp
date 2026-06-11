#include<bits/stdc++.h>
using namespace std;

int main()
{int n,ans = 0;
cin>>n;
string s ;
cin>>s;
string z(s);
sort(s.begin(),s.end());
for(int i =0 ;i<n;i++)
if(z[i]!=s[i])
ans++;
cout<<(ans+1)/2<<endl;

       return 0;
}