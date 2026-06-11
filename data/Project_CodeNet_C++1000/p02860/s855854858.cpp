#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
int main()
{
ll n,c=0; cin>>n;
string s; cin>>s;
if(n%2==1) cout<<"No"<<endl;
else {
for(int i=0;i<n;i++)
{
    if(s[i]==s[n/2+i])
    {
        c++;
    }
}
if(c!=n/2) cout<<"No"<<endl;
else cout<<"Yes"<<endl;
}

}
