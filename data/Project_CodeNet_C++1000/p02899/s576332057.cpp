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
int a[100001];
int b[100001];


int main(){
    cin >> n;
    rep(i,n){
        int idx = i+1;
        cin >> a[idx];
        b[a[idx]] = idx;
    }
    rep(i,n) cout << b[i+1] << " " ;
    cout << endl;


return 0;
}