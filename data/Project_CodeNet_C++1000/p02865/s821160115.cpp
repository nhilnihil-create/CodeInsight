#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P =pair<int,int>;

int main(){
    int N;
    cin>>N;
    if(N%2==0){
        cout<<(N/2)-1<<endl;
    }else{
        cout<<N/2<<endl;
    }
return 0;}
/*compile
g++ code.cpp
./a.out
run*/
/*
int f(int x){
    int y=int((x*x+4.0)/8.0);
    return y;
}
*/