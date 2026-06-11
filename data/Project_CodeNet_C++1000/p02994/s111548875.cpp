#include <iostream>
using namespace std;
int main(void){
    int n,l,r,eat;
    cin >> n >> l;
    r = n+l-1;
    if(r<=0) eat=r;
    else if(l>=0) eat=l;
    else eat=0;
    cout << (r+l)*(r-l+1)/2-eat;
}