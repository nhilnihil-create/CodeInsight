#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
#define PI 3.141592653589

int main(){
    int n, x;
    cin >>n;
    int a[100];
    for(int i=0;i<n;i++){
        cin >>x;
        a[i]=x;
    }
    for(int i=n-1;0<=i;i--){
        cout <<a[i];
        if(i!=0)cout <<" ";
    }
    cout <<endl;
    return 0;
}