#include<bits/stdc++.h>
using namespace std;
typedef vector <int> vi;
typedef set <int> se;
#define endl "\n"
#define for(i,a,b) for(int i = a;i<b;i++)
#define all(v) v.begin(),v.end()
#define ff first
#define ss second
#define ll long long
#define mod 1000000007
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


void solve(){
int n,x,t;
cin>>n>>x>>t;

int ans = 0;
while(n>0){
    ans+=t;
    n -= x;
}
cout<<ans<<endl;

}
 
 
int main()
{

solve();
 
return 0;
}