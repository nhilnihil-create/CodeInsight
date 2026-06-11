#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> P;
typedef long long ll; 

#define int ll

main(){
	int n;
	cin >> n;
	char s[n+1];
	cin >> s;

	char pass[4];
	pass[3] = 0;

	int ans = 0;

	for(int i=0;i<1000;i++){
		pass[2] = '0'+i%10;
		pass[1] = '0'+(i/10)%10;
		pass[0] = '0'+(i/100)%10;
		bool b2 = false;
		bool b1 = false;
		bool b0 = false;
		
		for(int j=0;j<n;j++){
			if(!b0 && pass[0]==s[j]){
				b0 = true;
			}else if(b0 && !b1 && pass[1]==s[j]){
				b1 = true;
			}else if(b0 && b1 && !b2 && pass[2]==s[j]){
				b2 = true;
			}
		}
		if(b0 && b1 && b2){
			ans++;
			//cout << pass << endl;
		}
	}

	cout << ans << endl;

	return 0;
}
