#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int N,M;
    cin >> N >> M;
    int A[N];
    for(int i=0;i<N;i++) cin >> A[i];
   
    long double sum_vote = 0;
    for(int i=0;i<N;i++) sum_vote += A[i]; 
    
    double limit = sum_vote / (4*M);
    int count = 0;
    for(int i=0;i<N;i++){
        if(limit<=A[i]) count++;
    }
    
    if(count>=M) cout << "Yes";
    else cout << "No";
    
}
