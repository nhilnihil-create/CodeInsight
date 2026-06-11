//??????????????????not working
#include<iostream>
#include<iomanip>
#include<cmath>
#include<complex>
using namespace std;

typedef complex<double> xy_t;

void koch(int n,xy_t s,xy_t t){

    if(n==0){
        return;
    }
    
    xy_t a,b,c;
    double th=M_PI*60.0/180.0;
    xy_t rot(cos(th),sin(th));
    
    a=(2.0*s+1.0*t)/xy_t(3,0);
    c=(1.0*s+2.0*t)/(xy_t(3,0));
    b=rot*(c-a)+a;

    koch(n-1,s,a);
    cout<<fixed<<setprecision(8)<<a.real()<<" "<<a.imag()<<"\n";
    koch(n-1,a,b);
    cout<<fixed<<setprecision(8)<<b.real()<<" "<<b.imag()<<"\n";
    koch(n-1,b,c);
    cout<<fixed<<setprecision(8)<<c.real()<<" "<<c.imag()<<"\n";
    koch(n-1,c,t);
}

int main(){
   xy_t s(0,0);
   xy_t t(100,0);
   int n;
   cin>>n;

   cout<<fixed<<setprecision(8)<<s.real()<<" "<<s.imag()<<"\n";
   koch(n,s,t);
   cout<<fixed<<setprecision(8)<<t.real()<<" "<<t.imag()<<"\n"; 
}