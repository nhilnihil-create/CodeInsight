#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin>> N >> M;

    vector<int> A(N);
    int sum = 0;
    for(int i=0; i<N; i++){
        cin>> A[i];
        sum += A[i];
    }
    
    sort(A.begin(), A.end() ,greater<int>());
  /*  
    for(int i=0; i<M; i++){
        if(sum/(4*M) > A[i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
*/
if(A[M-1] >= (sum+(4*M-1))/(4*M)){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}
    return 0;
}