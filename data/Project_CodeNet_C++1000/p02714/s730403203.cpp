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
    string S; cin>>S;

    int R = 0;
    int G = 0;
    int B = 0;
    for(int i=0;i<N;i++){
        if(S.at(i)=='R')R++;
        if(S.at(i)=='G')G++;
        if(S.at(i)=='B')B++;
    }
    int ans = R*G*B;

    int index = 0;
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            int k = i+(j-i)*2; 
            if(k>=N)break;
            if(S.at(i)!=S.at(j)&&S.at(i)!=S.at(k)&&S.at(j)!=S.at(k))index++;
        }
    }
    cout<<ans-index<<endl;



    return 0;
}