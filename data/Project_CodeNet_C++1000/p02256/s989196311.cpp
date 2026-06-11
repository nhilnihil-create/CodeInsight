#include <iostream>

using namespace std;

int gcd(int,int);

int main(){
    int x,y;
    cin>>x>>y;
    int i;
    int gcdans;
    if (x>=y) gcdans=gcd(x,y); else gcdans=gcd(y,x);
    cout<<gcdans<<endl;
    return 0;
}

int gcd(int a,int b){
    if (b==0){
        return a;
    }
    return gcd(b,a%b);
}