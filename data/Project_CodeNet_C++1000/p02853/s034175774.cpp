#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int a,b;

	cin >> a >> b;
	int ans = 0;
	if(a==1) ans+= 300000;
	if(b==1) ans+= 300000;
	if(a==2) ans+= 200000;
	if(b==2) ans+= 200000;
	if(a==3) ans+= 100000;
	if(b==3) ans+= 100000;
	if(a==1&&b==1) ans += 400000;
  
  cout << ans << endl;

	return 0;
}
