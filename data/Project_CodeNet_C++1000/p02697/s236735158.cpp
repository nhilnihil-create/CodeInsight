#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
using ll = long long;

int main(){
 int n, m;
  cin >> n >> m;
  
  vector<int> a(m), b(m);
  rep(i, m){
    a[i] = i+1;
    if(n % 2 ==0){
    	if(i+1 <= n/4) b[i] = n - i;
    	else b[i] = n - a[i];
    }
    else
    	b[i] = n - i;  
    cout << a[i] <<  " " << b[i] << endl;
    }
   
    return 0;
  }
    
    