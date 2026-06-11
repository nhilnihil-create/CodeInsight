#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main(){
    int L;
    cin>>L;
    double a=(double)L/3;

    cout<<fixed<<setprecision(7)<<a*a*a<<endl;
    

    return 0;
}