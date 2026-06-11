#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;

    vector<int> X(a);
    vector<int> Y(b);
    vector<int> C(c);

    for(int i = 0; i < a; i++) cin>>X[i];
    for(int i = 0; i < b; i++) cin>>Y[i];
    for(int i = 0; i < c; i++) cin>>C[i];

    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    sort(C.begin(),C.end());

    vector<int> z;

    for(int i = 0; i < x; i++) z.push_back(X[a-i-1]);
    for(int i = 0; i < y; i++) z.push_back(Y[b-i-1]);

    sort(z.begin(),z.end());

    for(int i = 0; i < x+y; i++){
        if(!C.empty() && C.back() > z[i]){
            z[i] = C.back();
            C.pop_back();
        } else break;
    }

    ll res = 0;
    for(int i : z) res+=i;
    cout<<res;

}
