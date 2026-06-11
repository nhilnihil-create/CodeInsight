#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    bool test = false;
    cin >> n;
    for(int i=1;i<=9;i++){
        for(int j=1; j<=9; j++){
            if(i*j==n){
               i=10;
               j=10;
               test = true;
            }
        }
    }
   
    if(test) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}