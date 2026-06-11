#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,len;
    cin >> N;
    len = N * 0.9;
    
    for(int i=len;i<=N;i++){
        if((int)(i* 1.08) == N){
            cout << i <<endl;
            break;
        }
       
       if(i == N) cout << ":(" <<endl;
    }
    
}