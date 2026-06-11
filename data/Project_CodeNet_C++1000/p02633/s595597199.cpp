#include <bits/stdc++.h>
using namespace std ;
int main(){
    int X;
    cin >> X;
    int A=0;
    int Ans;
    for(int i=1;i<=360;i++){
        A = A+X;
        A = A%360;
        if(A==0){
            Ans = i;
            break;
        }
    } 
    cout << Ans  << endl;  
 }