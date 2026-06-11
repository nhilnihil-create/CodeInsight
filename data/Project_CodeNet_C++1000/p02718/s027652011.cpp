#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int N,M,C=0,k=0;
    cin >> N >> M;
    
    int data[N];
    
    for(int i=0;i<N;i++){
        cin >> data[i];
        C += data[i];
    }
  
    double max = C / (4.0 * M);
    
    for(int i=0;i<N;i++){
        if(max <= data[i]){
            k++;
        }
        
        if(k == M){
            cout << "Yes" <<endl;
            return 0;
        }
    }
    
    cout <<"No" <<endl;
}