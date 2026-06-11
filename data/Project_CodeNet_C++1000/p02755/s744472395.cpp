#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {


    int A, B;
    cin >> A >> B;
    
    for(int i = 0; i < 1e6; i++){
        if(floor(i*0.08) == A && floor(i*0.10) == B){
        cout << i << endl;
        return 0;
        }
    }
    cout << "-1" << endl;
    

    return 0;
}