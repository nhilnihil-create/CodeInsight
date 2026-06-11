#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int m,d;
    cin>>m>>d;
    int ans=0;
    rep(i,1,m+1){
        int d1,d10;
        rep(j,1,d+1){
            d1=j%10;
            d10=j/10;
            if(d1>=2&&d10>=2&&d1*d10==i)ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
