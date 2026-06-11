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

int cnt;
int n;
int ans;
int h[100000];

int main(){
    cin >> n;
    rep(i,n){
        cin >> h[i];
    }
    rep(i,n-1){
        if(h[i] < h[i+1] ){
            ans = max(ans,cnt);
            cnt = 0;
            continue;
        }
        cnt++;
        if(i == n-2){
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;


return 0;
}