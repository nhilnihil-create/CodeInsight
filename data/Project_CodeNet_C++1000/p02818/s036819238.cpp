#include<iostream>
using namespace std;
int main(){
    long long int A,B,K;
    cin >> A >> B >> K;
    if(A>K){
        A = A -K;
        cout << A << " " << B;
    }
    else if(A<K && K>=A+B){
        cout << 0 << " " << 0;
    }
    else{
        cout << 0  << " " << B-K+A;
    }
}