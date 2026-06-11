#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i*j == x){
                cout << "Yes" << "\n";
                return 0;   
            }    
        }    
    }
    cout << "No" << "\n";
}
