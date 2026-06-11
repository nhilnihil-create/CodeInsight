#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int K,N;
    cin>>K>>N;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    int max_d=0;
    for(int i=0;i<N-1;i++){
        if(max_d<A[i+1]-A[i]){
            max_d=A[i+1]-A[i];
        }
    }
    if(max_d<K-A[N-1]+A[0]){
        max_d=K-A[N-1]+A[0];
    }

    cout<<K-max_d<<endl;
    
    return 0;
}