#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    long double a,b,x;
    cin >> a >> b >> x;
    long double pi = 3.14159265358979311599796346854418516159057617187500;
    if(2*x >= a*a*b){
        long double deg1 = atan(2*b/a - 2*x/(a*a*a));
        cout << fixed << setprecision(16);
        cout <<  deg1*180/pi << endl;
    }
    else{
        long double deg2 = atan(a*b*b/(2*x));
        cout << fixed << setprecision(16);
        cout << deg2*180/pi << endl;
    }
}
