
///*****************************************************///
///*.......................Faiyaj Bin Amin............................*///
///*...................................................................*///
///*.........................KUET CSE 2K17......................*///
///*...................................................*///
///*****************************************************///

#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

#define fastio      ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)
#define ret return
#define rep(q, i, n) for(int q=i; q<n; q++)
#define forn(i, n) for(int i=0; i<n; i++)
#define mems(a,x) memset(a,x,sizeof(a))
#define ll long long
#define pb push_back
#define em emplace_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define pii pair<int,int>
#define pdd pair<double, double>

#define see(x)        cerr<< __LINE__ << ": " << (#x) << " is "<< (x) <<'\n';
#define seecontent(v) for(auto x : v) { cout << x << " ";} cout << "\n\n";

#define PI 2*acos(0.0)
#define lcm(a, b)  ((a / __gcd(a, b) ) * b)

#define filein freopen ("input.txt", "r", stdin)
#define fileout freopen ("output.txt", "w", stdout)

#define mx 100005
#define INF 1e18
#define MOD 1000000007
#define MIN 0

//template <typename T>  using orderedSet =
//    tree<T, null_type, less_equal<T>,
//    rb_tree_tag, tree_order_statistics_node_update>; //find_by_order, order_of_key


/*------------------------------Graph Moves----------------------------*/
//const int fx[]={+1,-1,+0,+0}; // Directional
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*---------------------------------------------------------------------*/

/**------------------------------------BITMASK------------------------------------------**/
//int Change(int N, int pos){return N= N^(1<<pos);}
//bool Check(int N, int pos){return (bool)(N &(1<<pos));}  /// check bit 0 or 1
/**-----------------------------------------------------------------------------------------------**/

//using namespace __gnu_pbds;
using namespace std;

int main()
{
    fastio;

    int r,c;
    cin >>r>>c;

    char a[r][c], x;

    forn(i, r)
    {
        forn(j, c)
        {
            cin >> x;
            a[i][j]=x;
        }
    }

    int dp[r][c];

    if(a[0][0]=='#')
        dp[0][0]=1;
    else
        dp[0][0]=0;

    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(i==0 && j==0)
                continue;
            else if(i==0)
            {
                dp[i][j] = dp[i][j-1] + ((a[i][j-1]=='.' && a[i][j]=='#') ? 1:0);
            }
            else if(j==0)
            {
                dp[i][j] = dp[i-1][j] + ((a[i-1][j]=='.' && a[i][j]=='#') ? 1:0);
            }
            else
            {
                dp[i][j]=min(dp[i-1][j] + ((a[i-1][j]=='.' && a[i][j]=='#') ? 1:0),
                             dp[i][j-1] + ((a[i][j-1]=='.' && a[i][j]=='#') ? 1:0));
            }
        }
    }

    cout << dp[r-1][c-1] << "\n";
    return 0;
}

