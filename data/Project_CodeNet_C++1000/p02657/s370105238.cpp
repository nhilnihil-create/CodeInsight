#include<bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
 
//****************************************************                
#define f(var,start,end) for(ll var = start; var <end ; ++var)
#define rf(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define vvll vector<vector<ll>>
#define mtp make_tuple
#define ff first
#define ss second
#define vll vector<ll>
#define pll pair<ll,ll> 
#define vpll vector<pll>
#define all(X) X.begin(),X.end()
#define nl cout<<"\n"
#define trace1(a) cerr << #a << ": " << a << endl;
#define trace2(a,b) cerr << #a << ": " << a << " " << #b << ": " << b << endl;
#define trace3(a,b,c) cerr << #a << ": " << a << " " << #b << ": " << b << " " << #c << ": " << c << endl;
#define trace4(a,b,c,d) cerr << #a << ": " << a << " " << #b << ": " << b << " " << #c << ": " << c << #d << ": " << d << endl;
#define OC freopen("input.txt" , "r", stdin); freopen("output.txt" , "w", stdout) 
#define MOD (ll)1e9+7; //change it for other mods
#define FAST_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
        //*******************************************************
//Some Functions
void solve();

int binary(int a[],int l,int r,int find)
{
    if(l>r)
    {
        return -1; 
    }else
    {
        int mid=(l+r)/2;
        if(a[mid]==find)
        {
            return mid+1;
        }else if(a[mid]>find)
        {
            binary(a,l,mid-1,find);
        }else
        {
            binary(a,mid+1,r,find);
        }   
    }   
}

int main()
{
    FAST_IO;
    ll testcases = 1;
    // cin >> testcases; //comment for 1 test case
    while(testcases--)
    {
        solve();
    }
}

void solve()
{
	ll a,b;
	cin>>a>>b;
	ll p=a*b;
	cout<<p;
	nl;   
}