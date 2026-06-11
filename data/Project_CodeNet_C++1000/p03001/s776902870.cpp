#include "bits/stdc++.h"
using namespace std;
typedef long double ld;
int main() {
    ld w,h,x,y;
    cin>>w>>h>>x>>y;
    if(w==2*x&&h==2*y){
        cout<<fixed<<setprecision(10)<<(w*h)/2<<" "<<1;
    }
    else cout<<fixed<<setprecision(10)<<(w*h)/2<<" "<<0;
}