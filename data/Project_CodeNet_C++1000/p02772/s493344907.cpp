#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    int N,A;
    cin >> N;
    
    bool OK=true;
    for(int i=0;i<N;i++) {
        cin >>A;
        if(A%2==0){
            if(A%3!=0&&A%5!=0) {
                OK=false;
            }
        }
    }
    if(OK==true) {
        cout << "APPROVED" << endl;
    }
    else {
        cout << "DENIED" << endl;
    }
    
}
