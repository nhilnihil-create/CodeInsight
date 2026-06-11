#include<iostream>
using namespace std;
int main(){
    int H,W,N,A; 
    cin>>H>>W>>N;
    A=max(H,W); 
    cout<<(N+A-1)/A;
    return 0;
}