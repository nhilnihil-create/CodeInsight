#include <bits/stdc++.h>
using namespace std;
using ll =long long;

int main(){
    string S; cin>>S;
    if(S[0]==S[1]||S[1]==S[2]||S[2]==S[3]){
        cout<<"Bad"<<endl;
        return 0;
    }
    cout<<"Good"<<endl;
}