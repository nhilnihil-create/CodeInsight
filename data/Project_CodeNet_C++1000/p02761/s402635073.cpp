#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N,M; cin >> N >> M;
    int s[M],c[M];
    for(int i=0;i<M;i++){
        cin >> s[i] >> c[i];
    }
    for(int i=0;i<1000;i++){
        bool flag=true;
        string res=to_string(i);
        if(res.size()!=N) continue;
        for(int j=0;j<M;j++){
            if(res[s[j]-1]!=c[j]+'0'){
                flag=false;
                break;
            }
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}