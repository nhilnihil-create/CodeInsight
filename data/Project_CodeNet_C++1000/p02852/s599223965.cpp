#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> p;
typedef long long ll;
typedef pair<ll,ll> pll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e9;
const ll MOD=1e9+7;

int main(){
    int N,M;cin>>N>>M;
    string s;cin>>s;
    reverse(s.begin(),s.end());
    vector<int> ans;
    int n=0;
    while(n<N){
        bool flag=true;
        for(int i=M;i>=1;--i){
            if(n+i>N) continue;
            if(s[n+i]=='0'){
                n+=i;
                ans.push_back(i);
               flag=false;
               break;
            }
        }
       if(flag){
         cout<<-1<<endl;
         return 0;
       }
    }
  reverse(ans.begin(),ans.end());
  for(int i=0;i<(int)ans.size();++i){
    cout<<ans[i];
    if(i<(int)ans.size()-1) cout<<' ';
  }
  cout<<endl;
}
              