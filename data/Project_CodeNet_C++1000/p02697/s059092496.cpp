#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;

int main(){
    int N, M; cin>>N>>M;
    //要するに二人の数の差は常に同じ
    //|ai-bi|およびN-|ai-bi|にダブりが出ないように決めればいい

    if(N%2==1){
    rep(i,M){
        cout<<1+i<<" "<< N-i<<endl;
    }
    }else{

    rep(i,M/2){
        cout<<1+i<<" "<< N-i<<endl;
        cout<<N/2-1-i<<" "<< N/2+1+i<<endl;
    }
    if(M%2==1){
        cout<<1+(int)M/2<<" "<< N-(int)M/2<<endl;
    }
    }



    return 0;
}