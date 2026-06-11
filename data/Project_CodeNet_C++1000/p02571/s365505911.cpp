#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    string s,t;
    cin>>s>>t;
    int ans=INF;
    rep(i,0,s.size()-t.size()+1){
        string ss=s.substr(i,t.size());
        int cnt=0;
        rep(j,0,t.size()){
            if(ss[j]!=t[j])cnt++;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}