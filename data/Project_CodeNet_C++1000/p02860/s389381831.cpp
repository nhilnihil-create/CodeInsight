#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    int N;
    string S;
    cin>>N>>S;
    if(N%2==0){
        if(S.substr(0,N/2)==S.substr(N/2,N/2))cout<<"Yes";
        else cout<<"No";
    }else{
        cout<<"No";
    }
    return 0;
}