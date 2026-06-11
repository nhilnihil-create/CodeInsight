#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;
int main()
{
    fast_io
    string s,t,x;
    ll s1,t1;
    cin>>s>>t;
    cin>>s1>>t1>>x;
    if(x==s) s1--;
    else if(x==t) t1--;
    cout<<s1<<" "<<t1<<endl;

    return 0;
}


