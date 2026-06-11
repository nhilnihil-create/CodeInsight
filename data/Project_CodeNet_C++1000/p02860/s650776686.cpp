#include<bits/stdc++.h>
#define ll 	long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
ll n; cin>>n;

string s; cin>>s;

string t=s.substr(0,n/2);
if(n==s.size()){

if(t+t==s)
cout<<"Yes\n";
else
cout<<"No\n";
}

else
cout<<"No\n";
    return 0;
}