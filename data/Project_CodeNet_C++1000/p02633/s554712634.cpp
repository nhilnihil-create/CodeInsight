#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;
    int lcm,div=x,divi=360,tmp;
    while(div!=0){
        tmp=divi;
        divi=div;
        div=tmp%div;
    }
    lcm = 360*x/divi;
    cout<<lcm/x;
    return 0;
}