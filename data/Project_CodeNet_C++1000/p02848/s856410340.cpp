#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    string S;
    cin>>N>>S;
    int len=S.size();
    rep(i,len){
        S[i]+=N;
        if(S[i]>'Z'){
            S[i]-=26;
        }
    }
    cout<<S<<endl;
}


