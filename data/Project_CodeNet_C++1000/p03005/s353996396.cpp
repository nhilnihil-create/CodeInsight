#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    int N,K;
    cin>>N>>K;
    int ball=N-K;
    if(K==1){
        cout<<0<<endl;
    }else{
        cout<<ball<<endl;
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/