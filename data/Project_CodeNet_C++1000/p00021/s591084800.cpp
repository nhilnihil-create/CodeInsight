#include<complex>
#include<iostream>
using namespace std;
typedef complex<double> P;

int cross(P a, P b, P c, P d);

int main(){
    int n;
    cin >>n;
    for(int i = 0; i < n; i++){
        P a, b, c, d;
        cin >>a.real() >>a.imag() >>b.real() >>b.imag() >>c.real() >>c.imag() >>d.real() >>d.imag();
        if(cross(a, b, c, d)){
            cout <<"YES" <<endl;
        } else{
            cout <<"NO" <<endl;
        }
    }
    return 0;
}
int cross(P a, P b, P c, P d){
    P x = a - b, y = c - d;
    int ret;
    if(!(x.real() * y.imag() - x.imag() * y.real())){
        ret = 1;
    } else{
        ret = 0;
    }
    return ret;
}