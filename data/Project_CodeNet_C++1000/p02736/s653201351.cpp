#include<iostream>
#include<cstring>
#define DIM 1000005
using namespace std;
int n, i, ok, x;
int fact[DIM];
char v[DIM];
int impar(){
    int i, nr = 0;
    for(i = 1; i <= n; i++){
        if(v[i] == 1 && fact[n - 1] == fact[i - 1] + fact[n - i]){
            nr++;
        }
    }
    return nr % 2;
}
int main(){
    cin>> n;
    cin>> v + 1;
    for(i = 1; i <= n; i++){
        v[i] -= '1';
    }
    for(i = 1; i <= n; i++){
        fact[i] = fact[i - 1];
        x = i;
        while(x % 2 == 0){
            fact[i]++;
            x /= 2;
        }
    }
    if( impar() ){
        cout<< 1;
    }
    else{
        ok = 0;
        for(i = 1; i <= n; i++){
            if(v[i] == 1){
                ok = 1;
            }
        }
        if(ok == 1){
            cout<< 0;
        }
        else{
            for(i = 1; i <= n; i++){
                v[i] /= 2;
            }
            if( impar() ){
                cout<< 2;
            }
            else{
                cout<< 0;
            }
        }
    }
}
