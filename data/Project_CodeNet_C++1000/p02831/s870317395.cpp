#include <bits/stdc++.h>
using namespace std ;
int main(){
    int A,B;
    cin >> A >> B;
    long int An=A,Bn=B;
    while(1){
        if(A<B)swap(A,B);
        if(!B)break;
        A%=B;
    }
    if(A==1){
        long int Ans = An*Bn;
        cout << Ans << endl;
    }else{
        long int Ans = An*(Bn/A);
        cout << Ans << endl;
    }
}