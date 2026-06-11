#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long int ll;
typedef unsigned long long int ull;
#define inf INT_MAX
#define minf INT_MIN
#define watch(x)	cout<<(#x)<<"=>"<<x<<'\n';
#define sz(a) (int)(a).size()
#define all(x) x.begin(),x.end()
#define MOD 1000000007 

ll ans;
int arr[300009];
vi vr;
void solve()
{
    int n;  cin>>n;
    ans = n;
    ans = ans * (n-1);
    ans = ans % MOD;
    for(int i = 2; i < n; ++i){
        ans = ((ans)*10)%MOD;
    }
    cout<<ans;

    cout<<'\n';
}

void sol(){
    int n;  cin>>n;
    ll tenn =1, ninen =1, aten = 1;

    for(int i = 0; i < n; ++i){
        tenn *= 10;
        tenn %= MOD;
        ninen *= 9;
        ninen %= MOD;
        aten *= 8;
        aten %= MOD;
    }
    ninen *= 2;
    ninen %= MOD;
    ans = (tenn - ninen) % MOD;
    if(ans < 0) ans += MOD;
    ans = (ans + aten) % MOD;
    cout<<ans;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int testc;  testc = 1;
    for(int t = 0; t < testc; ++t){
        sol();
    }
    return 0;
}

	//Sun 13 Sep 2020 05:46:43 PM IST


		/***astrainL3gi0N***/
