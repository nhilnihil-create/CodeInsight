#include<bits/stdc++.h>
#define lint long long
#define st first
#define nd second
#define INF 0x3f3f3f3f

using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int i = 0;
	for(int i=1;i<=5;i++){
		lint x; cin>>x;
		if(x==0){
			cout<<i<<"\n";
			return 0;
		}
	}	

	return 0;	
}
