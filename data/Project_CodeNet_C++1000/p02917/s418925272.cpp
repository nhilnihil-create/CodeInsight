#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>
#include<tuple>
#include<bitset>


using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define printfloat(x) cout << fixed << setprecision(7) << (x) << endl;
#define printbit(x) cout << bitset<15>(x) << endl;
using ll = long long int;



long double pi = 3.14159265359;

int b[100];
int n;
int ans;

int main(){
    cin >> n;
    rep(i,n-1) cin >> b[i] ;
    ans += b[0] + b[n-2];
    rep(i,n-2){
        ans += min(b[i],b[i+1]);
    }
    cout << ans << endl;


return 0;
}