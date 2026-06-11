#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    int n; cin>> n;
    vector<int> w(n);
    forin(w);
    vector<int> b(n+1, 0);
    rep(i, n){
        b[i+1] = b[i] + w[i];
    }

    int ans = 1e+9;
    for(int t=1; t<n; t++){
        int s1 = b[t];
        int s2 = b[n] - s1;
        ans = min(ans, abs(s1 - s2));
    }
    cout<< ans << endl;
}
