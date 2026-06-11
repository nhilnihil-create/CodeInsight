#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int n;
    int sumgcd = 0;
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){    
                sumgcd += gcd(gcd(i+1,j+1),k+1);
            }
        }
    }

    cout << sumgcd;

}