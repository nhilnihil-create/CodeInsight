#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ll long long
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pi acos(-1)
#define valid(x , y) x >= 1 && x <= 8 && y >= 1 && y <= 8
#define pb push_back
#define pll pair <ll, ll>
#define pii <pair<ll , ll>
#define mp make_pair
#define M (1e9 + 7)
#define sl1(t) scanf("%lld" , &t)
#define si1(t) scanf("%d" , &t)
#define sl3(t , u , v) scanf("%lld %lld %lld" , &t , &u , &v)
#define si3(t , u , v) scanf("%d %d %d" , &t , &u , &v)
#define sl2(t , u) scanf("%lld %lld" , &t , &u)
#define si2(t , u) scanf("%d %d" , &t , &u)
#define el printf("\n")
#define sp printf(" ")
#define pri(t) printf("%d " ,t)
#define prl(t) printf("%lld " , t)
#define pc(x) printf("Case %lld: " , x)
//int dx[] = {1 , -1  , 0 , 0 , 1 , -1 , 1 , -1};
//int dy[] = {0 , 0 , 1 , -1 , -1 , 1 , 1 , -1};

vector<ll>v[200005];
ll vis[200005];

ll cnt = 0;
ll cnt2 = 0;

void dfs(ll n)
{
    if(vis[n] != 0)return;
    vis[n] = cnt;
    cnt2++;
    for(ll i = 0 ; i < v[n].size() ; i++){
        dfs(v[n][i]);
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    ///*
    #ifndef ONLINE_JUDGE
    freopen("input.cpp", "r" , stdin);
    //freopen("output.txt" , "w" , stdout);
    #endif // ONLINE_JUDGE
    //*/
    ll n;cin >> n;
    ll sr = sqrt(n);
    ll num = 1;
    for(ll i = sr + 2 ; i >= 1 ; i--){
        if(n % i == 0){
            num = i;
            break;
        }
    }
    cout << num + (n / num) - 2 << endl;
    return 0;
}
