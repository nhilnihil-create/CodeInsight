#include<iostream>
#include<string.h>
#define max 1000000

using namespace std;

void gerar_crivo(bool[]);

bool primos[max];

int main(){
    int numero;

    memset(primos, true, sizeof(primos));

    gerar_crivo(primos);

    cin >> numero;

    if(primos[numero])cout << numero;
    else{
        while(primos[numero] == false)numero++;

        cout << numero;
    }
}

void gerar_crivo(bool v[]){
    int i, j;

    for(i = 2; i * i <= max; i++){
        if(v[i]){
            for(j = i * i; j <= max; j+=i){
                v[j] = false;
            }
        }
    }

}