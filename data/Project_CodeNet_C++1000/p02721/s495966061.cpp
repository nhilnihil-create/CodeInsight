#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
const static ll MOD = (1e+9)+7;

int main(){
    int N,K,C;cin>>N>>K>>C;
    string S;cin>>S;
    vector<int> left(N,-1);
    vector<int> right(N,-1);
    int before = -1;
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(S[i] == 'o'){
            if(before == -1 || i > before+C){
                left[i] = ++cnt;
                before = i;
            }
        }
    }
    if(cnt > K)return 0;
    before = N;
    for(int i=N-1;i>=0;i--){
        if(S[i] == 'o'){
            if(before == N || i < before-C){
                right[i] = cnt--;
                before = i;
            }
        }
    }
    rep(i,N){
        if(left[i] == right[i] && left[i]!=-1){
            cout<<(i+1)<<endl;
        }
    }
    return 0;
}