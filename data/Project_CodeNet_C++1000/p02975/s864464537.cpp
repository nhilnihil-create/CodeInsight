#include <bits/stdc++.h>
using namespace std;
#define pb push_back
long long n , x[300000] , jenis;
map<long long , int>m;
vector<int>v;
bool cek;
//m.count(x[i]) buat cari apakah ada x[i] di map nya
int main(){
	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i];
		if(m[x[i]] == 0) {
      jenis++;
      v.pb(x[i]);
    }
		m[x[i]]++;
		if(x[i] != 0)cek = true;
	}
	sort(v.begin() , v.end());
  if(!cek){
    cout << "Yes" << endl; 
    return 0;
  }
	if(v.size() == 3){
		if(m[v[0]] == n/3 && m[v[1]] == n/3 && m[v[2]] == n/3){
			if((v[0]^v[1]^v[2])== 0){
				cout << "Yes" << endl;
        return 0;
			}	
		}	
	}
	else if(v.size() == 2){
		if(v[0] == 0 && m[v[1]] == 2*n/3){
			cout << "Yes" << endl;
      return 0;
		}
	}
  
  cout << "No" << endl;
  return 0;
}