#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double x1,y1,x2,y2,ans;
    cin>>x1>>y1>>x2>>y2;
    ans=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    ans=sqrt(ans);
    cout<<setprecision(20)<<ans<<endl;
}