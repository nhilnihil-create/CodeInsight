#include<bits/stdc++.h>
using namespace std;
int main(void){
    int X,Y,legs;
    cin>>X>>Y;
    for(int i =0;i<=X;i++){
        legs = i*4 + (X-i)*2;
        if(legs == Y){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}