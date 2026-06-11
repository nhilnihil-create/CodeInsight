#include<iostream>

using namespace std;

int main(){
    long long int S;
    cin >> S;
    long long int x1,x2,x3,y1,y2,y3,I;
    I = 1000000000;
    x1=0;
    y1=0;
    x2=I;
    y2=1;
    if((I-S%I)==0){
        I/=0;
    }
    x3 = (I-S%I)%I;
    y3 = (S+x3)/I;
    printf("%lld %lld %lld %lld %lld %lld\n",x1,y1,x2,y2,x3,y3);
}
