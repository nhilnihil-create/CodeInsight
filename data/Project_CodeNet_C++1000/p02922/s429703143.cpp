#include <bits/stdc++.h>
using namespace std;
int main(){
    int A,B,count,k=1;
    
    cin >> A >> B;
    
    count = A;
    
    while(count < B){
        count += (A-1);
        k++;
    }
    if(B == 1) k = 0;
    cout << k << endl;
}