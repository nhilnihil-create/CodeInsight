#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
#define pb push_back
#define sx 200007
map<int,int> m1,m,m3;
map<pair<int,int>,int> ma;
int main()
{
    int n;
    cin>>n;
    int ans=n%1000;
    if(ans==0)
        cout<<ans<<endl;
    else
        cout<<1000-ans<<endl;
    return 0;
}
