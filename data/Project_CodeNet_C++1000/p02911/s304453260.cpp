#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using ll = long long;
 
int main(){
	int n, k, q;
  	cin >> n >> k >> q;
  	vector<int> a(n);
  	rep(i, q){
      	int res;
      	cin >> res;
      	res--;
 		a[res]++;
    }
  	
  	rep(i, n){
      	if(k-q+a[i] > 0) puts("Yes");
  		else puts("No");
   	}
}