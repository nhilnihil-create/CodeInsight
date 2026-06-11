#include<bits/stdc++.h>
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
s.find_by_order(x) xth element in set
x.order_of_key(x) number of elements <x*/
#define ll long long
#define vi vector<int>
#define si set<int>
#define mii map<int,int>
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define pii pair<int,int>
#define extract_word(s)  stringstream str(s); while(str>>word)
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SET(s) cout<<fixed<<setprecision(s)
#define set0(a) memset(a,0,sizeof(a))
#define endl "\n"
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lower_string(s) transform(all(s),s.begin(),::tolower())
#define upper_string(s) transform(all(s),s.begin(),::toupper())
#define size(s) (int)s.size()
template<typename T,typename U>
bool compare(T x,U y){return(abs(x-y)<=1e-9);}
const int MOD=1e9+7;
void solve()
{
fastio
int n,m;
cin>>n>>m;
int danger[m];
for(auto &x:danger)
cin>>x;
int dp[n+1];
for(auto &x:dp)
x=0;
dp[0]=0;
if(count(danger,danger+m,1))
dp[1]=0;
else
dp[1]=1;
if(count(danger,danger+m,2))
dp[2]=dp[1];
else
dp[2]=1+dp[1];
for(int i=3;i<=n;i++)
{
	if(!binary_search(danger,danger+m,i-1))
	dp[i]=(dp[i]+dp[i-1])%MOD;
	if(!binary_search(danger,danger+m,i-2))
	dp[i]=(dp[i]+dp[i-2])%MOD;
}
cout<<dp[n];
}
int main()
{
//code
fastio
int t;
t=1;
while(t--)
{
solve();
cout<<endl;
}
}
