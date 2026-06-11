#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N,K;
    cin>>N>>K;
    string res="";
    while(0<N){
        res=(char)(N%K+'0')+res;
        N/=K;
    }
    cout<<res.size();
}