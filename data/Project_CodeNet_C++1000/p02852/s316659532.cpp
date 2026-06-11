#include<bits/stdc++.h>
using namespace std;
#define FOR(i,l,r) for(long long i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define int long long
#define _GLIBCXX_DEBUG
const int INF=1e15;

signed main(){
    int N,M;
    cin>>N>>M;
    string S;cin>>S;
  	bool ok=true;
  	stack<int> s;
    for(int i=0;i<=N-1;){;
      	ok=false;
       	for(int j=0;j<=M-1;j++){
          if(N-i-(M-j)>=0&&S[N-i-(M-j)]=='0'){
                i+=M-j;
            	s.push(M-j);
            	ok=true;
            	break;
            }
        }
      	if(ok==false){
        	break;
        }
    }
    if(ok){
        while(s.empty()==0){
          cout<<s.top()<<" ";
          s.pop();
        }
    }
    else cout<<-1<<endl;
}
