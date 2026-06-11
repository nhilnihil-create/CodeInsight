#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
#pragma comment(linker, "/stack:200000000")
#define mod 100000007
#define ll long long int
#define inf ( ll  )( 1e9 + 10 )
#define mxs (int)( 1e5 + 1e5 + 10 )
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
int ans, t, n, m, i, j, k, a, b, c, d, g , q , cases;
string s , s2, s3, s4;
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);
    brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>m>>n;
    if ( n == 1 )
    {
        cout<<"0";
        return;
    }
    ans = m - n;
    cout<<ans;
}
