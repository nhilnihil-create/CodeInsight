#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin>>N;
    string S; cin>>S;
    if(N%2==1)cout<<"No"<<endl;
    else{
        for (int i = 0; i < N/2; i++){
            if(S[i]!=S[i+N/2]){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }
}