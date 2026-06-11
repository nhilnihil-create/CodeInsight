#include<bits/stdc++.h>
using namespace std;

int N, num_bb = 0;
vector<int> A(200010);


int main(){
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] != i+1-num_bb) ++num_bb;
    }

    if(num_bb == N) 
        cout << -1 << endl;
    else
        cout << num_bb << endl;
    
    return 0;

}

