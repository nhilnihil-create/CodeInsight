#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    double a,b,h,m;
    double pi = 3.1415926535897932384;
    cin >> a >> b >> h >> m;
    double r=min(360-abs(h*30.0-5.5*m),abs(h*30.0-5.5*m));
    cout << setprecision(15) << sqrt(a*a+b*b-2*a*b*cos(r/360.0*2.0*pi)) <<endl;
    return 0;
}
