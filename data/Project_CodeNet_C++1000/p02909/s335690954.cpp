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
    if(s[0] == 'S') cout << "Cloudy" << endl;
    else if (s[0] == 'C') cout << "Rainy" << endl;
    else cout << "Sunny" << endl;
    


return 0;
}