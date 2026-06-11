#include<iostream>
#include<cmath>
using namespace std;

int isPrime(int num){
    int i;
    if(num<=1) return 0;

    else if(num==2) return 1;
    if(num%2==0) return 0;
    for(i=3;i<=sqrt(static_cast<double>(num));i+=2){
            if(num%i==0) return 0;
        }
    return 1;
}

int main(){
    const int max=10000;
    int i,size,A[max],count=0;
    cin >> size;
    for(i=0;i<size;++i){
        cin >> A[i];
        if(isPrime(A[i]))++count;
    }
    cout << count <<endl;
    return 0;
}