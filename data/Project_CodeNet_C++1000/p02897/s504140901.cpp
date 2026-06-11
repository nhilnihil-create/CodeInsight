#include <bits/stdc++.h>
using namespace std;
int main(){
    double n;
    cin >>n;
    if(int(n)%2 == 0){
        cout<< 0.5;
    }
    else{
        double k = ((n+1)/n)*0.5;
        cout << k; 
    }
    return 0;
}

