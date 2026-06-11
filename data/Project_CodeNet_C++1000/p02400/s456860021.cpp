#include<iostream>
#include<math.h>
using namespace std;
int main(){
    double r,s,l;
    cin >> r;
    s = r*r*M_PI;
    l = 2*r*M_PI;
    
    cout << fixed << s << " " << fixed << l << endl;
    return 0;
}
