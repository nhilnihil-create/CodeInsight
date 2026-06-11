#include<bits/stdc++.h>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define w(x) scanf("%d",&x);while(x--)
#define ws(x) scanf("%d",&x);getchar();while(x--)
#define rep(i,b) for(i=0;i<=b;i++)
#define ios ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pi 2*acos(0.0)
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

const int N=1e6+2;
long long  mod=1e9+9;
int t,j,cs=0,n,a,b,i,k,x;
string s;

int main()
{
    cin>>n>>a>>b;
    k=b-a;
    int ar[n]={};
    for(i=0;i<b;i++){
        cin>>x;
        ar[x-1]++;
    }
    for(i=0;i<n;i++){
        if(ar[i]>k)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<endl;
    }
}

