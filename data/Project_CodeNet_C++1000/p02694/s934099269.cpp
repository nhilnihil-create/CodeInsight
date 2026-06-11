#include <iostream>
using namespace std;
#define int long long
signed main(){
    int x;
    cin>>x;
    int amt = 100;
    int yrs = 0;
    int interest;
    while(amt<x){
        interest = amt/100;
        amt+=interest;
        yrs++;
    }   
    cout<<yrs<<endl;
    return 0;
}