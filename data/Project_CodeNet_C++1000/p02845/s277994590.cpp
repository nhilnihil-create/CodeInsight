#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 1e9
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int n;
int c[100010];


int main() {
    cin>>n;
    ll ret=1;
    c[0]=3;
    rep(i,n){
        int x;
        cin>>x;
        ret=ret*c[x]%MOD;
        c[x]--;
        c[x+1]++;
    }
    cout<<ret<<endl;
}