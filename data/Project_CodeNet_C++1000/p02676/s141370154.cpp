#include<bits/stdc++.h>

using namespace std;

int main(){
    int K;
    string S;
    cin>>K;
    cin>>S;

    for(int i= 0; i < S.length(); i++){
        if(i>=K){
            cout<<"...";
            break;
        }else{
            cout<<S[i];
        }

    }
}
