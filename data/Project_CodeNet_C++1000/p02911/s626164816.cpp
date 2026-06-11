#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 100000;
ll mod = INF;

int n,k,q;
int point[maxn];

int main(){
    cin >> n>>k>>q;
    fill(point,point+n,q-k);
    rep(i,q){
        int a;
        cin >> a;
        a--;
        point[a]--;
    }
    rep(i,n){
        point[i]=-point[i];
        if(point[i]<=0)cout << "No"<<endl;
        else cout << "Yes"<<endl;
    }
    return 0;
}