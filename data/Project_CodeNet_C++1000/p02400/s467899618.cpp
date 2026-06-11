#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<math.h>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;++i)
#define mod 1000000007
using namespace std;
int main(){
    double r;   cin>>r;
    cout<<fixed;
    cout<<setprecision(5)<<M_PI*r*r<<" "<<setprecision(6)<<M_PI*2*r<<endl;
}
