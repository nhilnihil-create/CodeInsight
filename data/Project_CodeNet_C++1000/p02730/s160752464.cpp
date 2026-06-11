#include<bits/stdc++.h>
using namespace std;
int main(){
    string S; cin>>S;
    int n=S.length();

    for(int i=0; i<n; i++){
        if(S[i] != S[n-i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    int m=(n-1)/2;
    for(int i=0; i<m; i++){
        if(S[i] != S[m-i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    int o=(n+3)/2;
    int j=0;
    for(int i=o-1; i<n; i++){
        if(S[i] != S[n-j-1]){
            cout<<"No"<<endl;
            return 0;
        }
        j++;
    }

    cout<<"Yes"<<endl;
}
