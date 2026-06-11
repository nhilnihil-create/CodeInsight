#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll largemod(ll a,string b);
bool year(int n);
int main(void)
{
int n;
string s,x;
cin>>n>>s;
int ans=0;
for(int i=0;i<n-2;i++)
{
    x=s.substr(i,3);
    if(x=="ABC")
    {
        ans++;
    }
}
cout<<ans<<endl;



}




