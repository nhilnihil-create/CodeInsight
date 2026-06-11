#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int x,y,s;
	while(cin>>x>>y>>s && x){
		int ans = -1;
		for(int i=1;i<=s;i++){
			for(int j=1;j<=s;j++){
				int a1 = i*(x+100)/100;
				int b1 = j*(x+100)/100;
				if(a1+b1!=s) continue;
				int a2 = i*(y+100)/100;
				int b2 = j*(y+100)/100;
				ans = max(ans, a2+b2);
			}
		}
		cout << ans << endl;
	}
}