#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(A==B){
        if(B!=C){
            cout << "Yes\n";
            return 0;
        }else{
            cout << "No\n";
            return 0;
        }
    }else if(A==C){
        cout << "Yes\n";
        return 0;
    }else{
        if(B==C)cout << "Yes\n";
        else cout << "No\n";
    }
}