#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define N 246913

int main(){
    vector<bool> prim(N,true);
    
    for(int i=2; i<sqrt(N); i++){
        if(prim[i]){
            for(int j=2; j*i<N; j++){
                prim[i*j]=false;
            }
        }
    }
    
    while(1){
        int n;
        cin >> n;
        if(n==0) break;

        int count=0;
        for(int i=n+1; i<=2*n; i++){
            if(prim[i]){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}