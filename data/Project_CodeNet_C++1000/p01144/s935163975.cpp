#include <bits/stdc++.h>
using namespace std;

long long cnt;
vector<pair<long long, long long> > pd;
long long dd, pp;
long long n, m;


int main(){

  
  while(cin >> n >> m && (n || m)){

    
    int judge = 0;

    for(int i = 0; i < n; i++){
      cin >> dd >> pp;
      pd.push_back(make_pair(pp,dd));
    }
    sort(pd.rbegin(),pd.rend());
    for(int i = 0; i < n; i++){
      if(pd[i].second - m >= 0){
	cnt += (pd[i].second - m) * pd[i].first;
	for(int j = i+1; j < n; j++){
	  cnt += pd[j].first * pd[j].second;
	}
	m = 0;
	cout << cnt << endl;
	break;
      }else {
	m -= pd[i].second;
      }
    }
    if(m != 0) cout << 0 << endl;
    pd.clear();			     
    cnt = 0;
  }


}