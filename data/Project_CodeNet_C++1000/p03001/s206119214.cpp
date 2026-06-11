#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    double n,k,x,y;
    cin>>n>>k>>x>>y;
    cout<<fixed<<setprecision(12)<<n*k/2<<" ";
    if(2*x==n&&2*y==k)cout<<"1"<<endl;
    else cout<<"0"<<endl;
    return 0;
}