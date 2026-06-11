#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int sz = pow(2,n);
  vector<int> s(sz);
  rep(i,sz) cin >> s[i];
  sort(s.rbegin(), s.rend());

  if(sz==1) cout << "Yes" << endl;
  else{
    if(s[0]==s[1]) cout << "No" << endl;
    else{
      ll cap = n;
      ll ncap = n;
      priority_queue<ll> pq;

      pq.push(n);
      rep1(i,sz-1){
	vector<ll> tmp;
	ll same=1;
	ll cn;
	cn= pq.top();pq.pop();
	if(cn>0){
	  pq.push(cn-1);
	  tmp.pb(cn-1);
	  ncap += (cn-1)*2-cn;
	}
	while(i<sz-1 && s[i]==s[i+1]){
	  i++;
	  same++;	  
	  if(!pq.empty()){
	    cn = pq.top();pq.pop();
	  }
	  else continue;
	  if(cn>0){
	    pq.push(cn-1);
	    tmp.pb(cn-1);
	    ncap += (cn-1)*2 -cn;
	  }
	}

	//	cout << "cap same " << cap << " " << same << endl;
	//	cout << "ncap" << ncap <<endl;
	if(same>cap){
	  cout <<"No" << endl;
	  return 0;
	}
	cap=ncap;
	rep(j,tmp.size()) pq.push(tmp[j]);
	if(pq.empty()) break;
      }
      cout <<"Yes" << endl;
    }    
  }        
  return 0;
    

}
