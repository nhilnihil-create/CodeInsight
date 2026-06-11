#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;
typedef pair<int,int> P;

int main(void) {
    int A,B,C,D; cin >> A >> B >> C >> D;
    int flag = true;
    while(true) {
        if(flag) {
            C-=B;
            flag = false;
        }
        else {
            A-=D;
            flag = true;
        } 
        if(C<=0) {
            cout << "Yes" << endl;
            return 0;
        }
        if(A<=0) {
            cout << "No" << endl;
            return 0;
        }
    }
}