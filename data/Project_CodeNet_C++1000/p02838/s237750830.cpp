////=====Bismillahir Rahmanir Rahim=====////

/*                        ______
 _______   /\     |``\   |        |  /
    |     /  \    |__/   |____    |/
    |    / _ _\   |  \   |        |\
    |   /      \  |   \  |______  |  \

            Dept. of CSE
        Comilla  University

*/
#include<bits/stdc++.h>
#define pi 2*acos(0.0)
#define ll long long
#define FIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define Node struct node
#define spc " "
#define  E  2.71828182845904523536
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define valid(nx,ny) nx>=0 && nx<n && ny>=0 && ny<m
#define edl "\n"
#define infinity 10000000000000000
#define mod 1000000007
#define cn continue
using namespace std;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;
typedef vector<pii> vpi;
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a <<","<< spc;
    err(++it, args...);
    cout<<edl;
}
///Bit manipulation

bool checkbit(ll mask,ll bit){return mask & (1LL<<bit);}
int setbit(int mask,int bit){ return mask | (1<<bit) ; }
int clearbit(int mask,int bit){return mask & ~(1<<bit);}
int togglebit(int mask,int bit){return mask ^ (1<<bit);}
int bitno(int mask) {return (int)__builtin_popcount(mask);}

int fx[]={0,0,+1,-1};
int fy[]={+1,-1,0,0};

/// KNIGHT MOVE

int x_move[] = {2, 1, -1, -2, -2, -1, 1, 2};
int y_move[] = {1, 2, 2, 1, -1, -2, -2, -1};

///=====================================///

const long long maX=3e5+5;
//vector<ll>Graph[maX],cost[maX];
map<string,ll>check;
///check n=1;
///check corner case;
set<ll>Set;
ll sum[maX],ans[maX];
stack<ll>Stack;
deque<string>DQ1,DQ2;
 ll one[64],zero[64];
void solve(ll casses)
{
    ll n,i,j,cc=0;
    cin>>n;
    ll ara[n];
    for(i=0;i<n;i++)cin>>ara[i];
    for(ll musk=0;musk<60;musk++){
        for(i=0;i<n;i++){
            if(checkbit(ara[i],musk))one[musk]++;
            else zero[musk]++;
        }
    }
    ll ans=0;
    ll m=1e9+7;
    for(i=0;i<60;i++){
        ll x=pow(2,i);
        x%=m;
        ll y=(one[i]*zero[i])%m;
        ans+=(x*y)%m;
        ans%=m;
    }
    cout<<ans<<endl;
}
/******************************************************************************/
/******************************************************************************/
/******************************************************************************/
int main()
{
    ll test;
    test=1;
    //scanf("%lld",&test);
    ll casses=1;
    while(test--){
    solve(casses);casses++;
    }

return 0;
}
/*
6 8
1 2 3
1 3 7
2 4 7
3 4 2
3 5 3
5 4 5
5 6 11
4 6 3
*/

