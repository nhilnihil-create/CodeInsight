#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

bool isequal_array(int *Array1, int *Array2, int N);

int main(){
    int N;
    cin >> N;
    int P[N];
    int Q[N];

    for(int i=0; i<N; i++){
        cin >> P[i];
    }

    for(int i=0; i<N; i++){
        cin >> Q[i];
    }

    int default_perm[N];
    for(int i=0; i<N; i++){
        default_perm[i] = i+1;
    }

    int counter=0;
    int counter_P = 0;
    int counter_Q = 0;
    
    do{
        bool is_equal_P = isequal_array(P, default_perm, N);
        bool is_equal_Q = isequal_array(Q, default_perm, N);
        if(is_equal_P){counter_P = counter;}
        if(is_equal_Q){counter_Q = counter;}
        
        counter += 1;
    }while(next_permutation(default_perm, default_perm+N));

    cout << abs(counter_P - counter_Q) << endl;
    return 0;

}

bool isequal_array(int *Array1, int *Array2, int N){
    for(int i=0; i<N; i++){
        if(Array1[i] != Array2[i]){
            return false;
        } 
    }
    return true;
}