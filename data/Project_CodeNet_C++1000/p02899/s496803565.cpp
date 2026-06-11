#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int A[N+1],B[N+1];
    
    for(int i=1;i<=N;i++)cin>>A[i];
    
    for(int i=1;i<=N;i++){
        B[A[i]] = i;
    }
    
    for(int i=1;i<=N;i++){
        cout << B[i] ;
        if(i == N)cout<<endl;
        else cout << " ";
    }
}
