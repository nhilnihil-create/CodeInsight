#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll cnt[10][10];

int main(){
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        string s=to_string(i);
        int x=s[0]-'0';
        int y=s.back()-'0';
        cnt[x][y]++;
    }

    ll ans=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=cnt[i][j]*cnt[j][i];
        }
    }

    cout<<ans<<endl;
} 
