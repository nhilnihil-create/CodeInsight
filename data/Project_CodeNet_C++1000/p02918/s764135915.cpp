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

int n,k;
int cntl,cntr;
string s;
int ans;
map<int,int> mp;
int main(){
    cin >> n >> k;
    cin >> s;
    rep(i,n){
        if(s[i] == s[i+1]) ans++;
    }
    ans = min(n-1,ans+2*k);
    cout << ans << endl;

return 0;
}