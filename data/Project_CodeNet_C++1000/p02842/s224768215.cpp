#include<bits/stdc++.h>
using namespace std;

int main(){
    double n;
    cin>>n;
    double x = (n/1.08);
    if((int)(x*10) > 5){
        x= ceil(x);
    }
    else x = floor(x);
    if(int(x*1.08) != n)cout<<":(";
    else cout<<x;
}