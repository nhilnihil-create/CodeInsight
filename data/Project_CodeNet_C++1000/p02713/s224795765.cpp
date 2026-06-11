#include <bits/stdc++.h>
using namespace std;

int gcd3(int a, int b, int c){
    int pick=min(a,min(b,c));
    int ans;
    for(int i=1; i<pick+1; i++){
        if(a%i==0 && b%i==0 && c%i==0){
            ans=i;
        }
    }
    return ans;
}

int main() {
    int K; cin >>K;
    int sum=0;
    for(int i=1; i<K+1; i++){
        for(int j=1; j<K+1; j++){
            for(int k=1; k<K+1; k++){
                sum=sum+gcd3(i,j,k);
            }
        }
    }
    cout << sum << endl;
}


    