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

int n;
long double a, ans, rev;


int main(){
    cin >> n;
    rep(i,n){
        cin >> a;
        rev += 1/a;
    }
    ans = 1/rev;
    printfloat(ans);


return 0;
}