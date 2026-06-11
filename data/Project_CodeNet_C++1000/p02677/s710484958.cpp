#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define lli long long int
#define ll double
#define pii pair<int,int>
#define pll pair<long long int,long long int>
#define pci pair<char,int
#define mii map<int,int>
#define mll map<long long int,long long int>
#define mci map<char,int>
#define umii unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define umci unordered_map<char,int>
#define F first
#define S second
#define pb push_back
#define endl '\n'
#define mod 1000000007
using namespace std;
#define maxval 10003000

int main(){
   IOS;
lli t;t=1;//cin>>t;
while(t--){
lli a,b,h,m;cin>>a>>b>>h>>m;
lli c=h*60+m;
ll x=c*0.5;
ll y=m*6;

ll z=(x-y);
if(x<y) z=z+360.0;
z=(z*3.141592653589793238)/180.0;
ll v=(ll)a*(ll)a;
ll w=b*b;
c=2*a*b;
ll d=v+w-(c*cos(z));
cout<<setprecision(20)<<sqrt(d)<<"\n";



} 
    
    

    
return 0;    
}