#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
#define pb push_back
#define csl ios_base::sync_with_stdio(false); cin.tie(NULL)
#define reps(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) for(int i=0;i<int(b);i++)
#define first ff
#define second ss
typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;
#define M 998244353
int main()
{
    csl;
    int n,m;
    cin >> n >> m;
    int sum = 0;
    int a[m];
    rep(i,m)
    {
        cin >> a[i];
    }

    rep(i,m)
    {
        sum+=a[i];
    }

    int x = n-sum;
    if(x < 0)
        cout << -1 << endl;
    else
        cout << x << endl;
}
