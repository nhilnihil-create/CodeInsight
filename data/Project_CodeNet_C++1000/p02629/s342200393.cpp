#include<bits/stdc++.h>
#define pb emplace_back
#define ll long long
#define mp make_pair
#define PI acos(-1)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll i,j,k,x,y,z,m,n,t,a,b,c,l,r,q;
    cin>>n;
    string s;
    while(n)
    {
        n--;
        x=n%26;
        s+=x+'a';
        n/=26;
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
}






