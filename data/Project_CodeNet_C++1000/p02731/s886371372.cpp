#include<bits/stdc++.h>
using namespace std;
int main(){
    double l;
    while(cin>>l){
        double x=l/3.0;
        double ans=pow(x,3);
        cout << fixed<<setprecision(9) << ans << endl;
    }
    return 0;
}
