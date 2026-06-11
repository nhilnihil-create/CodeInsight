#include <bits/stdc++.h>
using namespace std;

int main(void){
   
    int a,b,r;
    unsigned long long int x;
    cin >> a >> b;

    if(a<b){
        int tmp = a;
        a = b;
        b = tmp;
    }
    x = (unsigned long long int)a * b;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    
    cout << x / b << endl;
}