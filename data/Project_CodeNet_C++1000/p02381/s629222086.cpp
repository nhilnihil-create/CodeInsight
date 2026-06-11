#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    for(;;){
        int n;
        double m,sum=0,sum2=0;
        cin >> n;
        if(n==0)break;
        else{
            double a[n];
            for(int i=0;i<n;i++){
                cin >> a[i];
                sum+=a[i];
            }
            m=sum/n;
            for(int i=0;i<n;i++){
                sum2+=pow(a[i]-m,2);
            }
            cout << fixed << setprecision(8) << sqrt(sum2/n) << endl;
        }
    }
    return 0;
}

