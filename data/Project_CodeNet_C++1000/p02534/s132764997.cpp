#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define Go_ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define ll long long int
#define llu long long unsigned int
#define pf printf
#define sf scanf
#define f first
#define s second
#define pb push_back
#define mk make_pair
#define pii pair<int ,int>
#define PII pair<ll ,ll>
 
int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[] = {0, 0, 1, -1};
int dy4[] = {1, -1, 0, 0};
 
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
const int Max=1e9+100;
const ll  MAX=1e18+500;
const int sz=110;


int main()
{
    Go_
    int a,b,c,i,j,k,q,p,x,y,ct,ct1,m,l,r,x1,y1,mn,h,sum1,in,z,mid,n,mx;
    char ch;
    double d;
    string str1,str2,str;
    bool bl,bl1;
    int t,cs=1;

    cin>>n;
    string pip="ACL";

    string ans="";
    for(i=1;i<=n;i++) ans+=pip;

    cout<<ans<<'\n';
    
    
}