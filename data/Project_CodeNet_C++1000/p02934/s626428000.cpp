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
    double x=0;
    double y=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x+=1/a[i];
    }
    cout<<fixed<<setprecision(7);
    cout<<1/x<<endl;
    return 0;
}