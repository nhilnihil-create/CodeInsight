#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
    string S;
    cin >> S;
    int ans = 0;
    if(S.find("RRR") != -1){
        cout << 3 << endl;
    }else if(S.find("RR") != -1){
        cout << 2 << endl;
    }else if(S.find("R") != -1){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
}