#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    ll x;
    cin>>x;
    rep(i,-500,500){
        rep(j,-500,500){
            if(pow(i,5)-pow(j,5)==x){
                cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }
    return 0;
}