#include <bits/stdc++.h>
using namespace std;

int main(){
    int A,B,C, me, t=0;
    cin >> A >> B >> C;
    if(A<B && A<C){
        t+=A;
        if(B<C){
            t+=B;
        }
        else{
            t+=C;
        }
    }
    else if(B<A && B <C){
        t+=B;
        if(A<C){
            t+=A;
        }
        else{
            t+=C;
        }
    }
    else{
        t+=C;
        if(A<B){
            t+=A;
        }
        else{
            t+=B;
        }
    }
    cout << t;
    return 0;
}