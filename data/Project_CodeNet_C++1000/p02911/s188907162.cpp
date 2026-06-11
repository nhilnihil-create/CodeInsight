#include <bits/stdc++.h>

using namespace std;
int n, k, q, t, a[100005];

int main () {
	cin >> n >> k >> q;
	for (int i=0;i<q;i++){
		cin >> t;
		a[t]++;
	}
	for (int i=1;i<=n;i++){
		if (k-(q-a[i])>0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
