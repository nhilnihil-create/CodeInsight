#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
const int maxn = 100000;
ll mod = INF;

int submit[maxn];
int WA=0;
int AC=0;

int main(){
    
    int n,m;
    cin >> n>>m;
    fill(submit,submit+n,0);

    rep(i,m){
        int p;
        string s;
        cin >> p;p--;
        cin >> s;
        if(submit[p]!=INF&&s=="WA"){
            submit[p]++;
        }else if(submit[p]!=INF&&s=="AC"){
            AC++;
            WA+=submit[p];
            submit[p]=INF;
        }
    }
    cout << AC<<" "<<WA<<endl;
    return 0;
}