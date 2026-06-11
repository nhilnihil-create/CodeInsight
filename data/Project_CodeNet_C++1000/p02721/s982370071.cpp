#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = (int)(j);i <= (int)(k);i ++)
#define debug(x) cerr<<#x<<":"<<x<<endl
#define fix cout<<fixed<<setprecision(20);
const int maxn=(int)1e6+5;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k,c;cin>>n>>k>>c;
    string s;
    cin>>s;
    int len=s.length();
    vector<int>L,R;
    int cnt=c+1;
    rep(i,0,len-1){
        if(s[i]=='o'&&cnt>c)L.push_back(i),cnt=0,debug(i);
        cnt++;
        if(L.size()==k)break;
    }
    cnt=c+1;
    for(int i=len-1;i>=0;i--){
        if(s[i]=='o'&&cnt>c)R.push_back(i),cnt=0,debug(i);
        cnt++;
        if(R.size()==k)break;
    }
    reverse(R.begin(),R.end());
    int ans=0;
    rep(i,0,L.size()-1)if(R[i]==L[i])cout<<L[i]+1<<endl;
}