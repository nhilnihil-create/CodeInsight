#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main(){
    int n;
    cout << setprecision(20);
    do{
        cin >> n;
        if (n==0)
            break;
        int a[n];
        double sum=0;
        double ava;
        for (int i=0;i<n;i++)
            cin >> a[i];
        for (int i=0;i<n;i++)
            sum+=a[i];
        ava=sum/n;
        sum=0;
        for (int i=0;i<n;i++)
            sum+=pow(a[i]-ava,2);
        cout << sqrt(sum/n) << endl;
    }while(0==0);
}
