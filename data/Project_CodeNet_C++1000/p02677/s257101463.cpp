#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
#define en M_PI*2

int main(){
    int a,b,h,m;
    cin >> a >> b >> h >> m;
    double min = en/60*m;
    double hour = en/720*(60*h+m);
    //cout << cos(min-hour) << endl;
    double c = a*a + b*b - 2*a*b*cos(min-hour);
    //cout << c << endl;
    //cout << pow(c,0.5) << endl;
    cout << fixed << setprecision(12) << pow(c,0.5) << endl;
}