#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    rep(i,0,k+1){
        if(c>b){
            if(b>a){
                cout<<"Yes"<<endl;
                return 0;
            }
            
        }
        if(a>=b)b*=2;
        else if(b>=c)c*=2;
    }
    cout<<"No"<<endl;
    return 0;
}