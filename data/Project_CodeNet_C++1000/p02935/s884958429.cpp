#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    double a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-1;i++){
        a[i+1]=(a[i+1]+a[i])/2.0;
    }
    cout<<fixed<<setprecision(10)<<a[n-1]<<endl;
    return 0;
}