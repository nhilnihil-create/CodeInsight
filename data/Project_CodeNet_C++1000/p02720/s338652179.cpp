#include<bits/stdc++.h>
using namespace std;
long long a[100009];
int k;
int main(){
    cin>>k;
    int i;
    for(i=1;i<=9;i++){
        a[i]=i;
    }
    int temp=1;
    while(k>=i){
        if(a[temp]%10==0){
            a[i++]= a[temp]*10;
            a[i++]= a[temp]*10+1; 
        }
        else if(a[temp]%10==9){
            a[i++]=a[temp]*10+8;
            a[i++]=a[temp]*10+9;
        }
        else{
            a[i++]=a[temp]*10+a[temp]%10-1;
            a[i++]=a[temp]*10+a[temp]%10;
            a[i++]=a[temp]*10+a[temp]%10+1;
        }
        temp++;
    }
    cout<<a[k];
}