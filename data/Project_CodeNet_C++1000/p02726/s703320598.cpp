#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    x--,y--;
    if(x>y) swap(x,y);

    vector<int> ans(n,0);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d=min(j-i,abs(i-x)+1+abs(y-j));
            ans[d]++;
        }
    }

    for(int i=1;i<n;i++){
        cout<<ans[i]<<endl;
    }
}
