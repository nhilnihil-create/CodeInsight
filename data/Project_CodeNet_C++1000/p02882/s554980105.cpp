#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <iomanip>
#include <map>
#include <queue>
#include <tuple>
#include <math.h>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef tuple<int,int,int> P;


int main(){
    double a,b,x;
    cin >> a >> b >> x;
    double th=a*a*b/2.;
    double pi=3.1415927;

    if(x<=th){
        double tmp=x*2./a/b;
        cout <<fixed << setprecision(15)<< atan(b/tmp)*180./pi << endl;
    }else{
        double tmp=(a*a*b-x)*2./a/a;
        cout <<fixed << setprecision(15)<< atan(tmp/a)*180./pi << endl;
    }


    return 0;
}