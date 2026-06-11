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
    map<string,ll> m;
    ll N;
    string S;
    cin>>N>>S;

    rep(i,0,N){
        ll now = ll(S[i]-'0');
        rep(j,0,100){
            string l = j<=9?"0" + to_string(j):to_string(j);
            if(m[l] > 0){
                if(m[l+to_string(now)] == 0)m[l+to_string(now)]++;
                //cout<<l<<now<<endl;
            }
        }
        rep(j,0,10){
            if(m[to_string(j)] > 0){
                if(m[to_string(j)+to_string(now)] == 0)m[to_string(j)+to_string(now)]++;
            }
        }
        if(m[to_string(now)] == 0)m[to_string(now)]++;
    }
    ll ans=0;
    rep(i,0,1000){
        string l;
        if(i <= 9)l += "0";
        if(i <= 99)l += "0";
        l += to_string(i);
        if(m[l] >= 1){
            ans++;
            //cout<<l<<endl;
        }
    }
    cout<<ans;
    return 0;
}