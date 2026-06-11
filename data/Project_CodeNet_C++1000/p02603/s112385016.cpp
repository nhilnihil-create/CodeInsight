#include <iostream>
using namespace std;
int max(int a,int b){
    return a>b?a:b;
}
int min(int a,int b){
    return a<b?a:b;
}

int main(void){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++)cin>>A[i];
    
    long long money = 1000;
    long long stock = 0;
    
    for(int i=1;i<N;i++){
        if(A[i-1] < A[i]){
            stock = money / A[i-1];
            money += stock*(A[i] - A[i-1]);
        }
    }
    cout << money << endl;
}
