#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double x[n],y[n],sum[4]={0,0,0,0};
    for(int i=0;i<n;i++) cin >> x[i];
    for(int i=0;i<n;i++) cin >> y[i];
    for(int i=1;i<4;i++){
        for(int j=0;j<n;j++) sum[i-1]+=pow(abs(x[j]-y[j]),i);
    }
    for(int i=1;i<=3;i++)
        cout << fixed << setprecision(7) << pow(sum[i-1],1/(i*1.000000)) <<endl;
    double ma=0;
    for(int i=0;i<n;i++){
        if(ma<abs(x[i]-y[i])) ma=abs(x[i]-y[i]);
    }
    cout << fixed << setprecision(7) << ma << endl;
    return 0;
}

