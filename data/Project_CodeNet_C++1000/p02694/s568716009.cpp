#include<bits/stdc++.h>
using namespace std;
 
int main(){
    long long x, y=100, cnt=0;
    cin>>x;
 
    while(true){
        if(x<=y){
            cout<<cnt<<endl;
            return 0;
        }
        cnt++;
        y=y+y/100;
    }
}