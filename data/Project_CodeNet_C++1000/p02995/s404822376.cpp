#include<iostream>
using namespace std;

long long GCD(long long x, long long y){
    if(x<y)swap(x,y);
    if(x%y==0){
        return y;
    }else{
        return GCD(y,x%y);
    }
}
long long num(long long n,long long c,long long d){
    long long G=GCD(c,d);
    long long L=c/G*d;
    return n-n/c-n/d+n/L;
}

int main(){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<num(b,c,d)-num(a-1,c,d)<<endl;
}
