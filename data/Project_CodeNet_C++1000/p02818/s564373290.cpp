#include <bits/stdc++.h>
using namespace std;
bool T=false;
int main(){
    long long A,B,K;cin>>A>>B>>K;
    if(A-K>=0)A-=K;
    else if(B-K+A>=0){
        B-=K-A;
        A=0;
    }
    else {
        A=0;B=0;
    }
    cout<<A<<" "<<B<<endl;
}