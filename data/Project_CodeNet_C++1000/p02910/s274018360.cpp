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

string s;

int main(){
    cin >> s;
    bool flag = true;
    rep(i,s.size()){
        // cout << flag << " " << i  << endl;
        if(i%2==0 && s[i] == 'L') flag = false;
        if(i%2 && s[i] == 'R') flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;


return 0;
}