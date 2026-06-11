#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll A,B,C,K;
    cin>>A>>B>>C>>K;
    if(K<=A){
        cout<<K;
    }
    else if(K<=A+B){
        cout<<A;
    }
    else if(K<=A+B+C){
        cout<<A-(K-(A+B));
    }
}