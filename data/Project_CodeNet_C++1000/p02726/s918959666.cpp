#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int cnt[2010];

int main(){
    int n,x,y;
    cin>>n>>x>>y;

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int tmp=min(j-i,abs(x-i)+1+abs(y-j));
            cnt[tmp]++;
        }
    }

    for(int i=1;i<n;i++){
        cout<<cnt[i]<<endl;
    }
}

