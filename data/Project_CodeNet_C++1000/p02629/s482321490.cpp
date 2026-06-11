#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N;
    cin>>N;
    ll len=1;
    ll pow26=26;
    while(1){
        if(N-pow26>0){
            N-=pow26;
            len++;
            pow26*=26;
        }else{
            break;
        }
    }
    N--;
    string name;
    pow26=1;
    for (int i = 0; i < len-1; i++){
        pow26*=26;
    }
    for (ll i = len; i > 0; i--){
        ll tmp=N/pow26;
        name.push_back((char)((int)'a'+tmp));
        N%=pow26;
        pow26/=26;
    }
    cout<<name<<endl;
}