#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    double ans=n/3.00*n/3.00*n/3.00;
    cout<<fixed<<setprecision(12);
    cout<<ans<<endl;
    return 0;
}