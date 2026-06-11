  /// DONOT COPY PASTA WITHOUT AUTHOR'S PERMISSION ///
 ///                   S S S                      ///
///                1 7 0 7 0 5 3                 ///

#include<bits/stdc++.h>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <stdlib.h>
#include<string>
///STL
#define mp make_pair
#define ss second
#define ff first
#define pb push_back
#define ist insert
///ONLINE JUDGE
#define io ios_base::sync_with_stdio;cin.tie(0);cout.tie(0)
#define READ freopen("input.txt","r", stdin)
#define case(i) "Case "<<i++<<": "
#define nscase(i) "Case "<<i++<<":"
///c shortcuts
#define sns(s) scanf("%s",&s)
#define snc(c) scanf("%c",&c)
#define snd(a) scanf("%d",&a)
#define snl(a) scanf("%lld",&a)
#define snul(a) scanf("%ull",&a)
///Loops
#define mem(a,b) memset(a, b, sizeof(a))
#define rep(i,k,n) for(int i=k;i<n;i++)
#define rev(j,n,k) for(int j=n;j>=k;j--)
#define TC int tc;cin>>tc;while(tc--)

///GCD LCM
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a / __gcd(a, b) ) * b)

///CONSTANTS
#define PI 2*acos(0.0)
#define MAX 1000000000
#define inf 1e18

///functions
#define base(n,b) floor(log(n)/log(b))+1
#define onecnt(x) __builtin_popcount(x)
#define to_binary(n,b) bitset<b>(n).to_string()

#define endl '\n'
#define esc cout<<"\n"

/*------------------------------Graph Moves----------------------------*/
///const int fx[]= {+1,-1,+0,+0};
///const int fy[]= {+0,+0,+1,-1};
///const int fx[]= {+0,+0,+1,-1,-1,+1,-1,+1};  // Kings Move
///const int fy[]= {-1,+1,+0,+0,+1,+1,-1,-1}; // Kings Move
///const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
///const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef std::map<long long,int> mli;
typedef std::map<long long,long long> mll;
typedef std::map<int,int> mii;

///PBDS
using namespace __gnu_pbds;
typedef tree<
ll,
null_type,//set to another type while using map
less<ll>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;

template <typename T>
std::string toString( T Number )
{
    std::ostringstream ss;
    ss << Number;
    return ss.str();
}

///constants
const ll ten5=100000;
const ll ten6 =1000000;
const ll ten7 =10000000;
const ll ten8 =100000000;
const ll ten9 =1000000000;
const ll mod=ten9+7;



int main()
{
    io;

    int n;
    cin>>n;

    string s;
    cin>>s;

    int cnt=1;

    bool pos=true;

    for(int i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            cnt++;
        }
    }

    cout<<cnt<<endl;


}

