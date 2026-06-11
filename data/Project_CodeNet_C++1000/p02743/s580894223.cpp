#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long int a,b,c;

    cin >> a >> b >> c;


    if(c - a - b > 0 && (c - a - b) * (c - a - b) > 4 * a * b ){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}