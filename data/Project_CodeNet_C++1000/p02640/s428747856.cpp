#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	lint x, y;
	cin>>x>>y;
	if(y%2 !=0 ){
		cout<<"No\n";
	}else{
		int per = y/2;
		if((per/2+per%2) <= x && x <=per){
			cout<<"Yes\n";
		}else{
			cout<<"No\n";
		}
	}

	return 0;	
}
