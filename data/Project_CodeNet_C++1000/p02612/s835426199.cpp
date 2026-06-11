#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){

    int n;
    cin>>n;
    if(!(n%1000)){cout<<0; return 0;}
    cout<<1000-(n%1000);

return 0;
}