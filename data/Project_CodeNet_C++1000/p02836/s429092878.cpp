#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int main(){
    string S;
    cin>>S;
    ll res=0;
    ll length=S.size();
    for(ll i=0;i<length;i++){
        if(S[i]!=S[length-1-i])res++;
    }
    cout<<res/2;
    return 0;
}