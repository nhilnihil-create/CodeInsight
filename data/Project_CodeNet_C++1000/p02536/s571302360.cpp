#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using P = pair<int, int>;
using ll = long long;

int main(){
	int n, m;
  	cin >> n >> m;
  	dsu d(n); //atcoderのライブラリ(union-find)
  
  	rep(i, m){
    	int a, b;
      	cin >> a >> b;
      	a--; b--;
      	
      	d.merge(a, b);
    }
  
  	//int cnt = d.groups().size();
  	int cnt = 0;
  	rep(i, n) if(d.leader(i) == i) cnt++;
  	
  	cout << cnt-1 << endl;
}