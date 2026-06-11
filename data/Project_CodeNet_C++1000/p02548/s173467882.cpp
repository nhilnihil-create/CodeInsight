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
    int n;
    cin>>n;
    int cnt=0;

    for(int i=1;i<n;i++)
    {
        cnt+=(n-1)/i;
    }
    cout<<cnt<<endl;
    return 0;
}
