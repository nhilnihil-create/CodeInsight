#include <iostream>
using namespace std;

int nC2(int n){
    return n*(n-1)/2;
}

int main(void){
    int n,m;
    cin>>n>>m;
    cout<<nC2(n)+nC2(m)<<endl;
}

