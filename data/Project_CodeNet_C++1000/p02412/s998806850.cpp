#include<iostream>
#include <stdio.h>
using namespace std;

int main(){
    int n,x;
    int c;
    int i,j,k;

    for (;;){
        cin >> n >> x;
        c=0;
        if (n==0 && x==0)break;
        for (i=0;i<n;i++){
            for (j=0;j<n;j++){
                for (k=0;k<n;k++){
                    if (i + j + k + 3 == x){
                        if (i==j || j==k || i==k){
                        
                        }else{
                            //cout << i + 1 <<" " << j + 1<< " " << k + 1<< endl;
                            c = c + 1;
                        }
                    }
                }  
            }    
        }
        cout << c/6 << endl;
    }
    
    return 0;
}