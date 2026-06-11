#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    rep(i,1,n+1){
        if(int(i*1.08)==n){
  //      cout<<int(i*1.08)<<" "<<i*1.08<<endl;
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<":("<<endl;
    return 0;
}