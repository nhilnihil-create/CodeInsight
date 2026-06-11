#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int  N;
    cin >> N;
    if(N%2==0){
        double Ans = 1.0/2;
        cout << An << Ans <<endl;
    }else{
        double Ans = (((double)N+1.0)/2)/(double)N;
        cout << An << Ans <<endl;
    }
}