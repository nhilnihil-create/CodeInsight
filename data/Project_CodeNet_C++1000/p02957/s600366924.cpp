#include <bits/stdc++.h>
using namespace std;

int main(void){
   
    int a,b;
    cin >> a >> b;
    if(a > b){
        for(int i=b;i<=a;i++){
            if(abs(a - i) == abs(b - i)){
                cout << i << endl;
                break;
            }
            if(i == a) cout << "IMPOSSIBLE" <<endl;
        }
    }
    else{
         for(int i=a;i<=b;i++){
            if(abs(a - i) == abs(b - i)){
                cout << i << endl;
                break;
            }
             if(i == b) cout << "IMPOSSIBLE" <<endl;
        }
    }
    
}