#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    if(N%2==0){
        int half=min(N/4,M);
        for(int i=0;i<half;i++){
            cout<<1+i<<" "<<N-i<<endl;
        }
        if(half<M){
            for(int i=half;i<M;i++){
                cout<<2+i<<" "<<N-i<<endl;
            }
        }

    }else{
        for(int i=0;i<M;i++){
            cout<<1+i<<" "<<N-i<<endl;
        }
    }

    return 0;
}