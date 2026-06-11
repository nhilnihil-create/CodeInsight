#include <bits/stdc++.h>
using namespace std ;
#define An setprecision(16) 
int main(){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++)cin >> A[i];
    int flag=0;
    for(int i=0;i<N;i++){
        if(A[i]%2==0){
            if(A[i]%3!=0&&A[i]%5!=0)flag--;
        }
    }
    if(flag==0)cout<<"APPROVED\n";
    else cout<<"DENIED\n";
}