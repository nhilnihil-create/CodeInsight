#include <bits/stdc++.h>
using namespace std;

#define ll     long long
#define fr     first
#define sec    second
#define rep(i,n)  for(i=0;i<n;i++)
#define vi     vector <int>
#define vc     vector <char>
#define vl     vector <ll>
#define vb     vector <bool>
#define pb     push_back
#define M      1000000007
#define ios    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define open   freopen("input.txt","r",stdin);
#define close  freopen("output.txt","w",stdout);
#define M_PI   3.14159265358979323846
#define pp     pair<int,int>
#define nn 100003
#define MM 1000000000
#define MN 1000000000000000000
int main()
{
    ios;
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    if(k<=a)
        cout<<k;
    else if(k>a && k<=(a+b))
        cout<<a;
    else
    {
        k=k-a-b;
        k=min(k,c);
        cout<<a-k;
    }
    return 0;
}
