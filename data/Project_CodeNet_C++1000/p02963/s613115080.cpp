#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<ll,ll> P;
 
vector<ll>g[10010];
bool visited[10010];
int main(void){
    ll S;
    cin>>S;
    ll x1 = 0,y1 = 0;
    ll x2 = 1,y2 = 1000000000;
    if(S<=1000000000){
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<" "<<y2<<" "<<0<<" "<<S<<endl;
    }
    else{
        ll c = 0;
        if(S%1000000000==0)c=S/1000000000;
        else c = S/1000000000 + 1;
        cout<<x1<<" "<<y1<<" "<<" "<<x2<<" "<<" "<<y2<<" "<<c<<" "<<c*1000000000-S<<endl;
    }
    return 0;
}