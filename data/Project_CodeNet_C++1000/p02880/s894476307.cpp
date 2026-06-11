#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    for (int i = 1; i < 10; i++){
        if(N%i==0 && N/i<=9){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}