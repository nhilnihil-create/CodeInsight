/*C - Sum of gcd of Tuples (Easy)*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(a < b){
        swap(a, b);
    }
    
    while(a%b > 0){
        int r = a%b;
        a = b;
        b = r;
    }
    return b;
}

int main(){
    int K;
    cin>> K;

    int sum = 0;
    for(int i=1; i<=K; i++){
        for(int j=1; j<=K; j++){
            for(int k=1; k<=K; k++){
                sum += gcd(gcd(i ,j), k);
            }
        }
    }
    cout<< sum <<endl;
    return 0;
}