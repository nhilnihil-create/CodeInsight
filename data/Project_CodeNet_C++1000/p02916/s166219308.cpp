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

int a[20],b[20],c[20];
int n;
int ans;
int null = -100;


int main(){
    cin >> n;
    rep(i,n) {cin >> a[i]; a[i]--;}
    rep(i,n) {cin >> b[i];}
    rep(i,n-1) {cin >> c[i];}
    int prev_dish = null;
    rep(i,n){
        int dish = a[i];
        ans += b[dish];
        // cout << b[dish] << endl;
        if(dish == prev_dish + 1){
            ans += c[prev_dish];
            // cout << "c" << c[prev_dish] << endl;
        }
        prev_dish = dish;
    }
    cout << ans << endl;

return 0;
}