#include <iostream>
#include<vector>
#include<cmath>
#include<iomanip>
#define ll long long
using namespace std;
#define rep2(i,a,n) for(int i=a;i<=n;i++)
int main(void){
    // Your code here!
int n;
cin>>n;

double mid= n/2;
if(n%2==0){
cout<<fixed<<setprecision(6)<<mid/n;    
}else{
    cout<<fixed<<setprecision(6)<<(mid+1)/n;
}
}
