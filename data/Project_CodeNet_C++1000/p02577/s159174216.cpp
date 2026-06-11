#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    string s;
    cin>>s;
    ll sum=0;
    rep(i,0,s.size()){
        sum+=s[i]-'0';
    }
    if(sum%9==0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}