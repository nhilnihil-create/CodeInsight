#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll> A(n);
    rep(i,n){
        ll a;
        cin>>a;
        a--;
        A[i]=a;
    }

    vector<ll> visit(n,-1);
    visit[0]=0;
    ll now=0;
    ll cnt=0;
    ll loop=0;
    while(cnt<=k){
        cnt++;
        now=A[now];
        if(visit[now]!=-1){
            loop=cnt-visit[now];
            break;
        }else{
            visit[now]=cnt;
        }
    }

    if(loop){
        ll nk=(k-visit[now])%loop;
        rep(i,nk)now=A[now];
    }else{
        now=0;
        rep(i,k)now=A[now];
    }

    cout<<now+1<<endl;
}