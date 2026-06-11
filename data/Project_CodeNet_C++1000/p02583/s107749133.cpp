#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    
    int i, j, k, N, count;
    cin >> N;
    count = 0;
    
    int L[N];
    for (i = 0; i < N; i++){
        cin >> L[i];
    }
    
    for (i = 0; i < N; i++){
        for (j = i; j < N; j++){
            for (k = j; k < N; k++){
                
                if (L[i] > L[j] && L[i] > L[k] && L[j] != L[k] && L[i] < L[j] + L[k]){
                    count++;
                } else if (L[j] > L[i] && L[j] > L[k] && L[i] != L[k] && L[j] < L[i] + L[k]){
                    count++;
                } else if (L[k] > L[i] && L[k] > L[j] && L[i] != L[j] && L[k] < L[i] + L[j]){
                    count++;
                }
            }
        }
    }
    
    cout << count << "\n";
    
    return 0;
}
