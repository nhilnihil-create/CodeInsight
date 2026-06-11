#include <bits/stdc++.h>
using namespace std;

    int main() {
        
        int k;
        cin >> k;
        int a = 7%k;
        
        for(int i=1; i<=k; i++){
            
            if(a%k==0){
                cout << i <<' ';
                return 0;
            }
            
            a*=10;
            a+=7;
            a%=k;
            
        }
        
        cout << -1 <<' ';
        
        return 0;
        }
