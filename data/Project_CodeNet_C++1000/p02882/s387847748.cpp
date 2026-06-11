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

long double a, b ,x;
long double w;
long double r;
long double pi = 3.14159265359 ;

int main(){
    cin >> a >> b >> x;
    if(x == a*b*a/2){
        long double h = 2*x/(b*a);
        w = atan(h/b);
    }
    else if(x > a*b*a/2){
        w = atan(-2/a*((x/(a*a))-b));
    }
    else{
        w = atan((a*b*b)/(2*x));
    }

    cout << setprecision(7) << w*180.0/pi << endl;

return 0;
}