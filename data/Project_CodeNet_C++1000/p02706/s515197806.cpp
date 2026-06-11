#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N,M;
    cin >> N >> M;
    
    for(int i=0;i<M;i++){
        int A_i;
        cin >> A_i;
        N -= A_i;
        if(N < 0){
            cout << -1 <<endl;
            return 0;
        }
        
        if(i == M-1) cout << N <<endl;
    }
}