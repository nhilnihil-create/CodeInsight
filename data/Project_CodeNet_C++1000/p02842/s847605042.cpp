#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    long long N;
    cin>>N;
    for(long long i=1;i<=N;i++){
        long long X=i*1.08;
        if(X==N){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<":("<<endl;
    return 0;
}

