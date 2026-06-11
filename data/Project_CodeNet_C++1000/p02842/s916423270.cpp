#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int  N;
    cin >> N;
    int B=-1;
    for(int i=0;i<=N;i++){
        int Ans = i*1.08;
        if(Ans==N){
            B=i;
            break;
        }
    }
    if(B==-1)cout << ":(" << endl;
    else cout << B << endl;
}