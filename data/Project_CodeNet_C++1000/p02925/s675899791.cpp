#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n;
    cin>>n;
    int d[n+1][n];
    int c[n+1];
    rep(i,n)rep(j,n-1)cin>>d[i+1][j+1];
    rep(i,n)c[i+1]=1;
    int bb[n+1];
    int ans=0;
    int b=1;
    while(b){
        b=0;
        ans++;
        memset(bb,0,sizeof(bb));
        for (int i=1;i<n+1;i++){
            if (bb[i]==1 || c[i]==n)continue;
            int num=d[i][c[i]];//闘う相手
            if (d[num][c[num]]==i && bb[num]==0){
                c[num]++;
                c[i]++;
                bb[num]=1;
                bb[i]=1;
                b=1;
            }
        }
    }
    //cout<<c[1]<<" "<<c[2]<<" "<<c[3]<<endl;
    rep(i,n){
        if (c[i+1]!=n){
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans-1<<endl;

    return 0;
}