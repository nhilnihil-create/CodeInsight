#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N; cin>>N;
    for (int i = 0; i < N; i++){
        int A; cin>>A;
        if(A%2==0 && A%3!=0 && A%5!=0){
            cout<<"DENIED"<<endl;
            return 0;
        }
    }
    cout<<"APPROVED"<<endl;
}