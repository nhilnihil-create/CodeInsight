#include <bits/stdc++.h>
using namespace std;
void verificar(int a,int b,int c,int &n){
    if((b<a&&b>c||b<c&&b>a))
        n++;
}
int main(){
    int n;
    int sum=0;
    
    cin >>n;
    int* arr=new int[n];
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    for(int i=1;i<n-1;++i){
        verificar(arr[i-1],arr[i],arr[i+1],sum);
    }
    cout <<sum;

    return 0;
}