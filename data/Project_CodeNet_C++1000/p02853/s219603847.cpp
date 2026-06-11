#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main() {
    int money=0;
    int X,Y;
    cin>>X>>Y;
    if(X==1&&Y==1){
        money+=400000;
    }
    if(1<=X&&X<=3){
        money+=(4-X)*100000;
    }
    if(1<=Y&&Y<=3){
        money+=(4-Y)*100000;
    }
    cout<<money<<endl;
return 0;}
/*compile
g++ code.cpp
./a.out
run*/