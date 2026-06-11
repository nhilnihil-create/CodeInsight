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

map<int ,int> mp;

long double pi = 3.14159265359;

int n,k,q;
int a;

int main(){
    cin >> n >> k >> q;
    rep(i,q) {
        cin >> a;
        mp[a-1]++;
    }
    rep(i,n){
        if(k > q - mp[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
return 0;
}