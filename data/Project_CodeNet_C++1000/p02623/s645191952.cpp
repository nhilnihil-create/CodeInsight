#pragma GCC optimize(2)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define debug  freopen("in.txt","r",stdin),freopen("out.txt","w",stdout);
#define pb push_back
#define all(x) x.begin(),x.end()
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const int maxn = 1e6+10;
const int maxM = 1e6+10;
const int inf = 0x3f3f3f3f;
const ll inf2 = 0x3f3f3f3f3f3f3f3f;


int N,M,K;
ll w1[maxn],w2[maxn];
void solve(){
    int ans = 0;
    for(int i = 1;i<=M;i++) w2[i] += w2[i-1];
    int idx = upper_bound(w2+1,w2+M+1,K) - w2;
    ans = idx-1;
    for(int i =1;i<=N;i++){
        if(K>=w1[i]){
            K-=w1[i];
            int idx = upper_bound(w2+1,w2+M+1,K) - w2;
            ans = max(ans,i + idx-1);
        }else break;
    }
    cout<<ans<<'\n';
}
int main(){
//    debug;
    ios;

    cin>>N>>M>>K;
    for(int i =1;i<=N;i++) cin>>w1[i];
    for(int i =1;i<=M;i++) cin>>w2[i];
    solve();


    return 0;
}