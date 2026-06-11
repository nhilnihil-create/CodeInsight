#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define all(a) (a).begin(), (a).end()


int main(){
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    string s = "Yes";
    while(true){
        C-=B;
        if(C <= 0) break;
        A-=D;
        if(A <= 0){
            s="No";
            break;
        }
    }
    cout << s << endl;
}
