#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int n;
  cin>>n;
  
  queue<string> q;
  q.push("a");
  
  while(!q.empty()){
    string s=q.front();q.pop();
    if(s.size()==n){
      cout<<s<<endl;
      continue;
    }
    
    char now='a';
    rep(i,s.size()) {
      if(s[i]==now) now++;
    }
    
    for(char u='a';u<=now;u++){
      q.push(s+u);
    }
  }
  
}



