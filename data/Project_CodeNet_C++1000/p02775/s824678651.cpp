#include <bits/stdc++.h>
#include <time.h>
#include <stdlib.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define ull unsigned long long
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/__gcd((a),(b))
#define clr(x) x.clear()
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vi>
#define mp make_pair
#define hell 1000000007
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pii>
#define vpll vector<pll>
#define all(a) a.begin(),a.end()
#define ign cin.ignore();

#define o_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define o_setll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set

using namespace std;
using namespace __gnu_pbds;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef MY_PROJECT
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll dp[1000010],dp_comp[1000010];

string s,complement;

ll compute(int num,bool is_main){
    if((is_main==true)&&(dp[num]!=-1)){
        return dp[num];
    }
    if((is_main==false)&&(dp_comp[num]!=-1)){
        return dp_comp[num];
    }
    if(is_main){;
        dp[num]=s[num]-'0'+compute(num+1,true);
        if(s[num]!='9'){
            dp[num]=min(dp[num],s[num]-'0'+1+compute(num+1,false));
        }
        return dp[num];
    }
    else{
        dp_comp[num]=complement[num]-'0'+compute(num+1,false);
        if(complement[num]!='9'){
            dp_comp[num]=min(dp_comp[num],complement[num]-'0'+1+compute(num+1,true));
        }
        return dp_comp[num];
    }
}

int main()
{
    IOS
    string str;
    s="0";
    cin>>str;
    s=s+str;
    int n=s.length();
    memset(dp,-1,sizeof(dp));
    dp[n-1]=s[n-1]-'0';
    complement.resize(n);
    complement[0]='0';
    bool found=false;
    for(int i=n-1;i>0;i--)
    {
        if(s[i]=='0'&&found==false){
            complement[i]='0';
        }
        else if(s[i]!='0'&&found==false){
            found=true;
            complement[i]='0'+(10-(s[i]-'0'));
        }
        else{
            complement[i]='0'+(9-(s[i]-'0'));
        }
    }
    memset(dp_comp,-1,sizeof(dp_comp));
    dp_comp[n-1]=complement[n-1]-'0';
    compute(0,true);
    cout<<dp[0];
    return 0;
}
