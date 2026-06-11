#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N; cin>>N;
    if(N%2==1){
        cout<<0<<endl;
    }else{
        ll cnt=0;
        ll t=N;
        while(t!=0){
            t/=5;
            cnt+=(t/2);
        }
        cout<<cnt<<endl;
    }
}
    