#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
    int H,W,N;
    cin>>H>>W>>N;
    if(H>=W){
        if(N%H==0){
            cout<<N/H<<endl;
        }else{
            cout<<(N/H)+1<<endl;
        }
    }else{
        if(N%W==0){
            cout<<N/W<<endl;
        }else{
            cout<<(N/W)+1<<endl;
        }
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/