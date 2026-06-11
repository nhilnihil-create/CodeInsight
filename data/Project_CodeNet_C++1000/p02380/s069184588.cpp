#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define debug(x) cout << "debug" << x << endl;
using namespace std;

int main(){
    double a, b, c;
    while(cin >> a >> b >> c){
        printf("%.8lf\n%.8lf\n%.8lf\n",a * b * sin(c*M_PI / 180) / 2, sqrt(a * a + b * b - (2 * a * b * cos(c*M_PI / 180))) + a + b, b * sin(c*M_PI/180));
    }
}