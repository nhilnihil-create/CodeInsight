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
    ll N,K;
    cin>>N>>K;
    v A(N);
    rep(i,0,N)cin>>A[i];
    bool changed = true;
    while(changed && K--){
        changed = false;
        vector <pair<ll,ll>> imos;
        rep(i,0,N){
            imos.PB(MP(i - A[i],1));
            imos.PB(MP(i + A[i] + 1,-1));
        }
        sort(all(imos));
        ll now = 0;
        ll sum = 0;
        rep(i,0,N){
            while(imos[now].first <= i){
                sum += imos[now].second;
                now++;
            }
            if(A[i] != sum){
                A[i] = sum;
                changed = true;
            }
        }
    }
    rep(i,0,N)cout<<A[i]<<" ";

    return 0;
}