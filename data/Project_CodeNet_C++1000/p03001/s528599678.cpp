#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    ll w,h,x,y;
    cin >> w >> h >> x >> y;
    double s = w*h*0.5;

    int c=0;
    if(x*2==w && y*2==h) c=1;

    cout << fixed << setprecision(7) << s << ' ';
    cout << c << endl;
}