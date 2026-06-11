#include<bits/stdc++.h>
using namespace std;
int main(){
    int M,D;
    cin>>M>>D;
    int k,l;
    k=D/10;
    int cont=0;

    for(int i=2;i<=k;i++){
        for(int j=2;j<10;j++){
            if(i*j<=M && (i*10+j)<=D){

                cont++;
            }
        }
        
    }
    cout<<cont<<'\n';
        
}