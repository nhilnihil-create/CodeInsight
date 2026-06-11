#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    cin>>a>>b>>c;
    swap(b,c);
    swap(a,b);
    cout<<a<<' '<<b<<' '<<c;
    return 0;
}
