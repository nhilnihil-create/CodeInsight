#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    string s;
    int ans=0;
    cin>>n>>s;
    for(int x=0;x<n;x++){
    string S=s.substr(x,n-x);
    
    vector<int> Z(S.size());
    Z[0] = S.size();
    int i = 1, j = 0;
    while(i < S.size()){
        while(i + j < S.size() && S[j] == S[i + j]) j++;
        Z[i] = j;
        if(j == 0) { i++; continue; }
        int k = 1;
        while(i + k < S.size() && k + Z[k] < j){
            Z[i + k] = Z[k];
            k++;
        }
        i += k; j -= k;
    }
    int m=n-x;
    for(int y=0;y<m;y++){
    	ans=max(ans,min(Z[y],y));
    }
}
   
    cout << ans <<endl;
    return 0;
}
