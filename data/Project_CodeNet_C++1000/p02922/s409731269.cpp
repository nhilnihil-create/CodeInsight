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

int a,b;
int unuse,cnt;
int main(){
    cin >> a >> b;
    unuse = a;
    cnt ++;
    if(b==1){
        cout << 0 << endl;
        return 0;
    }
    while(b > unuse){
        unuse += a - 1;
        cnt ++;
    }
    cout << cnt << endl;


return 0;
}