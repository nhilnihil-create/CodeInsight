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

int a,b;

int main(){
    cin >> a >> b;
    if(a <= 2*b) cout << 0 << endl;
    else cout << a-2*b << endl;


return 0;
}