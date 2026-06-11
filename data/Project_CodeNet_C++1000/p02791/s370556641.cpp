#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forin(in, n) for(int i=0; i<n; i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<" "
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int minnum = 200050;
    int cnt = 0;
    int n; cin>> n;
    vector<int> tmp;
    vector<int> p(n);
    forin(p, n);
    for(int i=0; i<n; i++){
        tmp.push_back(p[i]);
        minnum = min(minnum, p[i]);
        if(minnum == p[i]) cnt++;
    }
    cout<< cnt << endl;
}
