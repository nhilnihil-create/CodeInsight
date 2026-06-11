#include <bits/stdc++.h>
using namespace std;

int main(void){
    // Your code here!
    int N;cin>>N;
    long long m=1000;
    long long h=0;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    char x='0';
    for(int i=1;i<N;i++){
        if(x=='0'){
            if(A[i-1]<A[i]){
                x='1';
                h=m/A[i-1];
                m=m%A[i-1];
            }
            else if(A[i-1]>A[i]){
                x='2';//2は減少
            }
        }
        else if(x=='1'){
            if(A[i-1]>A[i]){//売り
                x='2';
                m+=h*A[i-1];
                h=0;
            }
        }
        else if(x=='2'){
            if(A[i-1]<A[i]){//買い
                x='1';
                h=m/A[i-1];
                m=m%A[i-1];
            }
        }
    }
    if(h>=1){
        m+=h*A[N-1];
    }
    cout<<m<<endl;
    return 0;
}
