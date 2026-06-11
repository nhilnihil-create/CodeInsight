#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int N; cin>> N;
    string c; cin>> c;

    int cnt_R = 0;
    rep(i, N){
        if(c[i] == 'R') cnt_R++;
    }

    int ans = 0;
    rep(i, cnt_R){
        if(c[i] == 'W') ans++;
    }
    cout<< ans << endl;
}
