#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N,X;
    cin >> N >> X;
    vector<int> D(N+1);
    D[0] = 0;
    
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        D[i+1] = D[i] + x;
    }
    
    int count = 0;
    
    for(int i=0;i<=N;i++){
        if(D[i]<=X) count++;
    }

    
    cout << count;
    return 0;
}