#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,A;
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> A;
        if(A % 2 == 0){
            if(A % 3 != 0 &&  A % 5 != 0){
                cout << "DENIED" << endl;
                return 0;
            }
        }
    }
    
    cout << "APPROVED" << endl;
}