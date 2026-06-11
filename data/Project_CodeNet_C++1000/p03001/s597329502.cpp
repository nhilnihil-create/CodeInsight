#include<iostream>
using namespace std;
using ll=long long;

int main(){
    double W,H,x,y;
    cin>>W>>H>>x>>y;
    double field=W*H/2;
    int check;
    if(W/2==x&&H/2==y){
        check=1;
    }else{
        check=0;
    }
    printf("%.9f %d\n",field,check);
    return 0;
}