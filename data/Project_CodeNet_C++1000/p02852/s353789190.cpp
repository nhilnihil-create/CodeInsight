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


#define MOD 1000000007
#define INF 1001001001
#define MIN -1001001001
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back
#define PF push_front
#define all(x) (x).begin(),(x).end()


using namespace std;
typedef long long ll;
typedef vector<ll> v;
typedef vector<vector<ll>> vv;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    ll N,M;
    cin>>N>>M;
    string S;
    cin>>S;
    ll now = N;
    v ans;
    bool ok = true;
    while(now != 0){
       for(int i = max(now-M,ll(0)); i< now; i++){
           if(S[i] == '0'){
               ans.PB(now-i);
               now = i;
           }
           else{
               if(i == now-1){
                   ok = false;
                   now = 0;
                   break;
               }
           }
       }
    }
    if(!ok)cout<<-1;
    else{
        for(int i = ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}