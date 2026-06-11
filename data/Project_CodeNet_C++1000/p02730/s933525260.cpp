#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string S; cin>>S;
    int judge=0;
    int N=S.length();

    for(int i=0; i<N; i++){
        if(S[i] != S[N-i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    int N2=(N-1)/2;
    for(int i=0; i<N2; i++){
        if(S[i] != S[N2-i-1]){
            cout<<"No"<<endl;
            return 0;
        }
    }

    int N3=(N+3)/2;
    int i2=0;
    for(int i=N3-1; i<N; i++){
        if(S[i] != S[N-i2-1]){
            cout<<"No"<<endl;
            return 0;
        }
        i2++;
    }

    cout<<"Yes"<<endl;
}
