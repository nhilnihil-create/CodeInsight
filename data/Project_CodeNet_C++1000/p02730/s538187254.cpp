#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    string S;
    cin >> S;

    rep(i, S.size()/2){
        if(S[i]!=S[S.size()-1-i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    rep(i, S.size()/2/2){
        if(S[i]!=S[S.size()/2-1-i]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    for(int i=S.size()/2; i<S.size()/2/2*3; i++){
        if(S[i]!=S[S.size()-1-i]){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}