#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int main(){
    int x; cin >> x;

    for(int i = x; i < 1000003; i++){
        bool f = true;
        for(int j = 2; j <= i / 2; j++){
            if(i % j == 0) f = false;
        }
        if(f){
            cout << i << endl;
            return 0;
        }
    }
}