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
    vec_int A(N); rep(i,N)cin>>A.at(i);

    sort(A.begin(),A.end());


    rep(i,N-1){
        if(A.at(i)==A.at(i+1)){
            cout<<"NO"<<endl;
            return 0;
        }

    }

            cout<<"YES"<<endl;
    return 0;
}