#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int H,N,A;
    cin >> H >> N;
    
    for(int i=0;i<N;i++){
        cin >> A;
        H -= A;
        if(H <= 0){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    
    cout << "No" <<endl;
}