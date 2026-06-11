#include <bits/stdc++.h>
using namespace std;
int main(void){
    int N=5, i ;
    vector<int> x(N);
    for (i=1;i<N;i++){
        cin >> x[i];  
    }
    for (i=1;i<=N;i++){
        if (x[i]==0){
            cout << i << endl;
            break;
        }
    }
}
