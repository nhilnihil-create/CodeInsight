#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N,K,S; cin >> N >> K >> S;
    int ans[N];
    fill(ans,ans+N,INF);
    if(S==INF){
        for(int i=0;i<N-K;i++){
            ans[i]=1;
        }
    }else{
        for(int i=0;i<K;i++){
            ans[i]=S;
        }
    }
    for(int i=0;i<N;i++){
        cout << ans[i] << " ";
    }
}