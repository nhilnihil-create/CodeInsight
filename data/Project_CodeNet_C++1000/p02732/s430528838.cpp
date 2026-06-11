#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int N; cin>>N;
    vec_int A(N);rep(i,N)cin>>A.at(i);


    vec_int numCount(N+1,0);

    rep(i,N){
        numCount.at(A.at(i))++;
    }

    int tot = 0;
    rep(i,N+1){
        tot+=(numCount.at(i)*(numCount.at(i)-1))/2;
    }

    rep(i,N){
        int temp = ((numCount.at(A.at(i)))*(numCount.at(A.at(i))-1))/2;
        int temp2 = ((numCount.at(A.at(i))-1)*(numCount.at(A.at(i))-2))/2;
        cout<<tot-temp+temp2<<endl;
    }




    return 0;
}