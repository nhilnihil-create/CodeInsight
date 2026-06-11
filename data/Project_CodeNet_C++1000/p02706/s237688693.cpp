#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,M,total=0;
    cin >> N >> M;
    int A[M];
    for(int i=0;i<M;i++){
        cin >> A[i];
        total += A[i];
    }
    if(total > N)cout << -1 << endl;
    else cout << N - total << endl;
    
}