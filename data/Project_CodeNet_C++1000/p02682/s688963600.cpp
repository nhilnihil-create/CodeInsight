#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int A,B,C,K,sum=0;
    cin >> A >> B >> C >> K;
    
    for(int i=0;i<A;i++){
        sum++;
        K--;
        if(K == 0) break;
    }
    
    if(K == 0){
        cout << sum << endl;
        return 0;
    }
    
    for(int i=0;i<B;i++){
        K--;
        if(K == 0) break;
    }
    
    if(K == 0){
        cout << sum << endl;
        return 0;
    }
    
     for(int i=0;i<C;i++){
        sum--;
        K--;
        if(K == 0) break;
    }
    
    if(K == 0){
        cout << sum << endl;
        return 0;
    }
}