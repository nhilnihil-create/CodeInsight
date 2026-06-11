#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    long long int now=100;
    long long int X;
    cin>>X;
    for(int i=0;;i++){
        if(now>=X){
            cout<<i<<endl;
            return 0;
        }
        now=now+now/100;
 
    }
    return 0;
}