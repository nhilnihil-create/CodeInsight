#include <bits/stdc++.h>
using namespace std;
bool T=true;

int main(){
    int N;cin>>N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i];
        if(A[i]%2==0&&(A[i]%3!=0)&&(A[i]%5!=0))T=false;
    }
    if(T)cout<<"APPROVED";
    else cout<<"DENIED";
}