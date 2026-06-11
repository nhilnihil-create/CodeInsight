#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B, C;
    cin>>A>>B>>C;

    int T;
    T=B+C;

    if(A>=T){cout<<0<<endl;}
    else{cout<<T-A<<endl;}
}
