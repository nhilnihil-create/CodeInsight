#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define MX              200005
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define pw(b,p)         pow(b,p) + 0.1
#define ull unsigned long long
#define ll long long


void add(int &a,int b){
    a+=b;
    if(a>=mod)
        a-=mod;
}

int32_t main()
{
    int a,b,c;cin>>a>>b>>c;
    if(a+b+c>=22){
        cout<<"bust"<<endl;
    }else cout<<"win"<<endl;
    return 0;
}
