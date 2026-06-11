#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	long long a,b,x,y,total=0;
	
	cin >> a >> b;
	
	while(a--){
		cin >> x >> y;
		if(sqrt(x*x + y*y)<=b){
			total++;
		}
	}
	cout << total << endl;
}