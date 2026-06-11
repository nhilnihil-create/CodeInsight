#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int N, M; cin>> N >> M;
    vector<int> s(M), c(M);
    rep(i, M){
        cin>> s[i] >> c[i];
        s[i]--;
    }

    for(int i = 0; i<= 999; i++){
        stringstream iss;
        iss << i;
        string ii = iss.str();
        if(ii.size() == N){
            bool judge = true;
            rep(i, M){
                if(ii[s[i]] != c[i] + '0') judge = false;
            }
            if(judge){
                cout<< i << endl;
                return 0;
            }
        }
    }
    cout<< -1 << endl;
}