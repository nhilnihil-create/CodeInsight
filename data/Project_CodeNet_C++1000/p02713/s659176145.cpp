#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    int k,ans=0;
    cin>>k;
    for(int a=1;a<=k;a++)
        for(int b=1;b<=k;b++)
            for(int c=1;c<=k;c++)
               ans+=__gcd(a,__gcd(b,c));
    cout<<ans;

}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
