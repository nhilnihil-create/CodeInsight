#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin>>m>>n;
    int adap=m;
    int cont=0;
    if(n>1){
        cont=1;
        while(adap<n){
            adap+=(m-1);
            cont++;
        }
    }
    cout<<cont<<endl;
    
    return 0;
}
/*
1 1 1 
1 1 1 1
*/