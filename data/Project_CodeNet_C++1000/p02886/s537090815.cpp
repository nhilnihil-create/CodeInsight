#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << setprecision(7) << (x) << endl;

long double pi = 3.14159265359;

int n,d[100];

int main(){
    cin >> n;
    rep(i,n) cin >> d[i];
    int ans=0;
    rep(i,n){
        rep(j,n){
            if(i==j) continue;
            ans += d[i]*d[j];
        }
    }
    cout << ans/2 << endl;


return 0;
}