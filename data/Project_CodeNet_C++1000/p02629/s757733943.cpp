#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define mod 1000000007
#define Mod 998244353
#define pi 3.14159265358979323846
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;

int main()
{
    ll n;
    cin>>n;
    ll sum=0,cur=26,p=0;
    string ans="";
    string A="zabcdefghijklmnopqrstuvwxy";
    while(n)
    {
        ans=A[n%26]+ans;
        if(n%26==0) n-=26;
        else n-=n%26;
        n/=26;
    }
    cout<<ans<<endl;
    return 0;
}
