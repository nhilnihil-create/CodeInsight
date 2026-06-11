#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, K;
    cin >> A >> B >> C >> K;
    for(int x=0; x<=K; x++) for(int y=0; x+y<=K; y++){
        int b = B<<x, c = C<<y;
        if(A < b && b < c){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
