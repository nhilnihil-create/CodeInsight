//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n,m,cnt=0,mcnt=0,ans=0,cur=0; cin>>n>>m;
    string s; cin>>s;
    reverse(al(s));
    rep(i,n-1){
        if(s[i+1]=='0') cnt=0;
        else cnt++;
        mcnt=max(mcnt,cnt);
    }
    if(mcnt>=m){
        cout<<-1<<endl;
        return 0;
    }
    stack<int> lans;
    while(cur<n){
        int to;
        ans++;
        rep(i,m){
            if(cur+i+1>n) break;
            if(s[cur+i+1]=='0') to=cur+i+1;
        }
        lans.push(to-cur);
        cur=to;
    }
    rep(i,ans){
        cout<<lans.top()<<" ";
        lans.pop();
    }
    cout<<endl;
}