#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    string S;
    cin>>S;
    int len=S.size();
    int cnt=0;
    rep(i,len/2){
        if(S[i]!=S[len-i-1]){
            cnt++;
        }
    }
   cout<<cnt<<endl;
}


