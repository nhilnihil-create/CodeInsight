#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    int n;
    cin>>n;
    vector<double>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        double y;
        cin>>y;
        x[i]=abs(x[i]-y);
    }
    double s1=0,s2=0,s3=0,sinf=0;
    for(int i=0;i<n;i++){
        s1+=x[i];
        s2+=x[i]*x[i];
        s3+=x[i]*x[i]*x[i];
        sinf=max(sinf,x[i]);
    }
    s2=sqrt(s2);
    s3=cbrt(s3);
    cout<<fixed<<setprecision(10);
    cout<<s1<<endl<<s2<<endl<<s3<<endl<<sinf<<endl;
    
}

