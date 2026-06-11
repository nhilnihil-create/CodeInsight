#include <bits/stdc++.h>
using namespace std;

int main(void){
    bool isPrime[100004];
    for(int i=0;i<100004;i++) isPrime[i]=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=0;i<100004;i++){
        if(isPrime[i]==true){
            for(int j=i*2;j<100004;j+=i) isPrime[j]=false;
        }
    }
    int X;
    cin >> X;
    for(int i=X;i<100004;i++){
        if(isPrime[i]){
            cout << i;
            break;
        }
    }
}