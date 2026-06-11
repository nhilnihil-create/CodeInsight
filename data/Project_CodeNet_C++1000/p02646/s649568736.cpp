#include <bits/stdc++.h>
using namespace std;

#define DEBUG 0
 


int main() {
    long long A,B, V, W, T;

    cin >> A >> V >> B >> W >> T;

    long long length = (V - W) * T;


    if(abs(B-A) <= length){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;

 
}

