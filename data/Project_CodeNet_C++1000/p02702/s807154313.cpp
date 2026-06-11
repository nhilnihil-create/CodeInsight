#include <bits/stdc++.h> 
#include <vector>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<vector<int>>;

template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}

const int m=2019;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    reverse(s.begin(),s.end());
    int tot=0,x=1;
    ll ans=0;
    vector<int> cnt(m);
    rep(i,n){
        cnt[tot]++;
        tot+=(s[i]-'0')*x;
        tot%=m;
        ans+=cnt[tot];
        x=x*10%m;
    }
    cout<<ans<<endl;
    return 0;
}