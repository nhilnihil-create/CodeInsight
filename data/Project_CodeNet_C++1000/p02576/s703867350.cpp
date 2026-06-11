/*Anuranjan Srivastava (codersaty)*/
#include<bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
#define pinf INT_MIN
#define minf INT_MAX
#define loop(i,j) for(int i=1;i<=j;i++)
#define rep(i,j) for(int i=0;i<j;i++)
#define deb(x) cout<< #x << "=" << x<< endl
#define deb1(x,y) cout<< #x << "=" << x<<","<< #y << "=" << y<< endl
#define endl "\n"
#define F first
#define S second
#define mp make_pair
#define all(x) x.begin(),x.end()
#define clr(x) memset(x,0,sizeof(x))
#define  sortall(x) sort(all(x))
#define  tr(it,a) for(auto it=a.begin();it!=a.end();it++)
#define  pii pair<int,int>
#define  pll pair<ll,ll>
#define vi vector<int>
#define vl vector<ll>
#define vpii vector<pii>
#define vpl vector<pl>
#define  vvi vector<vi>
#define mi map<int,int>
#define ml map<ll,ll>
const double pi=3.141592653589793238;
using namespace std;


int main()
{
    int n,x,t;
    cin>>n>>x>>t;
    cout<<((int)ceil((double)n /x))*t;
}
