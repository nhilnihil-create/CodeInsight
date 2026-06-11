//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ld pie=3.1415926535;
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,k; cin>>n>>k;
    if((n-1)*(n-2)/2<k){
        cout<<-1<<endl;
    }
    else{
        cout<<n-1+(n-1)*(n-2)/2-k<<endl;
        rep(i,n-1) cout<<i+1<<" "<<n<<endl;
        int cnt=(n-1)*(n-2)/2-k;
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                if(cnt==0){
                    i=n; j=n; continue;
                }
                cout<<i<<" "<<j<<endl;
                cnt--;
            }
        }
    }
}