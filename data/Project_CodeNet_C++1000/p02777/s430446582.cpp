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
    string S,T;
    cin>>S;
    cin>>T;

    int A, B;cin>>A>>B;
    string U; cin>>U;

    if(U==S){
        cout<<A-1<<" "<<B<<endl;
    }else{
        cout<<A<<" "<<B-1<<endl;

    }


    return 0;
}