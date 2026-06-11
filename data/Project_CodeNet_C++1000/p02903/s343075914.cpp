#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
#define rep2(i,a,n) for(int i=a;i<n;i++)
#define been(ix) (ix).begin(),(ix).end()
using namespace std;
typedef long long ll; 
typedef vector<int> vi;
typedef vector<long long> vl;
const ll INFL = 1e18;
const int INF = 1001001001; 
typedef pair<int,int> P;
#define foreach(ix,i) for(auto& (ix) : (i))
typedef long double ld;
const int mod =1000000007;
const double PI = acos(-1);

int main(){
	int h,w,a,b;
    cin>>h>>w>>a>>b;
    vector<string> ans;
    string res;
    rep(i,a)res.push_back('1');
    rep(i,w-a)res.push_back('0');
    rep(i,b)ans.push_back(res);
    rep(i,w){
        if(res[i]=='0')res[i]='1';
        else res[i]='0';
    }
    rep(i,h-b)ans.push_back(res);
    int x=0;
    rep(i,h)cout<<ans[i]<<endl;
}