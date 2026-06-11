#include "bits/stdc++.h"
using namespace std;
int main(){
    int n,i,y,mac;
    double s1,s2,s3;
    mac = 0;
    s1=0;s2=0;
    s3=0;
    cin >> n;
    vector<int> x(n);
    for(i=0;i<n;i++) cin >> x.at(i);
    for(i=0;i<n;i++){
        cin >> y;
        x.at(i) -= y;
        x.at(i)=abs(x.at(i));
        if(mac < x.at(i))mac = x.at(i);
        s1 += x.at(i);
        s2 += x.at(i)*x.at(i);
        s3 += x.at(i)*x.at(i)*x.at(i);
    }
    s2 = sqrt(s2);
    s3 = cbrt(s3);
    printf("%.5lf\n%.5lf\n%.5lf\n%.5lf",s1,s2,s3,double(mac));
    return 0;
}
