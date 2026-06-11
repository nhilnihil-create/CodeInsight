#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const double PI=3.14159265358979323846;

int main(){
    double a,b,x;
    cin >> a >> b >> x;
    double H = a*a*b / 2;
    if(a<b){
        if(H < x){
            cout << fixed << setprecision(12) << atan(2*(a*a*b-x)/a/a/a) *360 /2 / PI << endl;
        }else{
            cout << fixed << setprecision(12) << 90 - atan(2*x/a/b/b) * 360/2/PI << endl;
        }
    }else{
        if(H < x){
            cout << fixed << setprecision(12) << atan(2*(a*a*b-x)/a/a/a) *360 /2 / PI << endl;
        }else{
            cout << fixed << setprecision(12) << 90 - atan(2*x/a/b/b) * 360/2/PI << endl;
        }
    }

}