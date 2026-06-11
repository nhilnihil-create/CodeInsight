#include<bits/stdc++.h>
using namespace std;

int main(){
	// sengen
	int n,k,r,s,p;
	string t;
	// nyuryoku
	cin >> n >> k;
	cin >> r >> s >> p;
	cin >> t;
	// keisan
	long long sum = 0;
	for(int i=0;i<n;i++){
		if(i < k){
			if(t[i] == 'r'){
				sum += p;
			}else if(t[i] == 's'){
				sum += r;
			}else{
				sum += s;
			}
		}else{
			if(t[i] == t[i-k]){
				t[i] = 'u';
			}else{
				if(t[i] == 'r'){
					sum += p;
				}else if(t[i] == 's'){
					sum += r;
				}else{
					sum += s;
				}
			}
		}
	}
	// syutsuryoku
	cout << sum;
}