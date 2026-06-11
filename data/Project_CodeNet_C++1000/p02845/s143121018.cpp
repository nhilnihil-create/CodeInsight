#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<iomanip>


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    ll N;
    cin>>N;
    v A(N);
    rep(i,0,N)cin>>A[i];
    ll a = 0,b = 0,c = 0;

    ll ans = 0;
    if(A[0] == 0){
        a++;
        ans = 3;
    }

    rep(i,1,N){
        ll x = 0;
        bool flag = false;
        if(a == A[i]){
            x++;
            a++;
            flag = true;
        }
        if(b == A[i]){
            x++;
            if(!flag){
                b++;
                flag = true;
            }
        }
        if(c == A[i]){
            x++;
            if(!flag){
                c++;
                flag = true;
            }
        }
        ans *= x;
        ans %= MOD;
    }
    cout<<ans;
    return 0;
}