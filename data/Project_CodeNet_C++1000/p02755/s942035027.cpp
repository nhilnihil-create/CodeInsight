#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, i;
    cin >> a >> b;
    for(i=0;i<=100000;i++){
        if(floor(i*0.08)==a && floor(i*0.1)==b){
            cout << i <<endl;
            return 0;
        } 
    }
    cout << -1 <<endl;
    return 0;
}