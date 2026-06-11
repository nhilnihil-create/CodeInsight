#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    int pass = 1;
    
    for(int i=0;i<N;i++){
        if(A[i] % 2 == 0 && (A[i] % 3 != 0 && A[i] % 5 != 0)){
            pass = 0;
        }
    }
    
    if(pass){
        cout << "APPROVED";
    }
    else{
        cout << "DENIED";
    }
    
}
