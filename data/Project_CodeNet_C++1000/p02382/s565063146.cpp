#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){
    double n,x[100],y[100],sum,max=0.0,D,p;
    int i;

    cout << fixed << setprecision(12);
    cin >> n;
    for(i=0;i<n;i++) cin >> x[i];
    for(i=0;i<n;i++) cin >> y[i];

    for(p=1.0;p<=3.0;p+=1.0){
        sum = 0.0;
        for(i=0;i<n;i++){
            sum += pow(fabs(x[i] - y[i]), p);
        }
        D = pow(sum, 1.0 / p);
        cout << D << endl;
    }

    for(i=0;i<n;i++){
        if(max < fabs(x[i] - y[i])) max = fabs(x[i] - y[i]);
    }

    D = max;
    cout << D << endl;
    return 0;
}

