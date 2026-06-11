#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const int INF = (1LL<<31)-1;
const int MOD = 1000000007;


vector<ll> a;
void dfs(int d, ll s){
    a.push_back(s);

    if(d>=10) return;

    for(int i=-1;i<=1;i++){
        int ad = s%10+i;
        if(ad >= 0 && ad <= 9) dfs(d+1,s*10+ad);
    }
}

int main(){
    int k; cin >> k;
    rep(i,9) dfs(1,i+1);
    sort(a.begin(),a.end());
    cout << a[k-1] << endl;
}