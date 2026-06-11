#include <bits/stdc++.h>
using namespace std;


int main(){
    int n,k,i,s;
    cin>>n>>k;
    i=1;
    s=k;
    while(n>=s){
        s*=k;
        i++;
    }
    printf("%d\n",i);
}