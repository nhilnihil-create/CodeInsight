#include <bits/stdc++.h>

using namespace std;

#define LL long int

const int MAX = 1e6;
const int MOD = 1e9+7;



int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int k;
    cin >> k;

    int count = 0;

    while(a >= b){
        b *= 2;
        count++;
    }

    while(b >= c){
        c *= 2;
        count++;
    }

    if(count <= k){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}