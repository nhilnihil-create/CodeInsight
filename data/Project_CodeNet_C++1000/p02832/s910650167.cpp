#include <bits/stdc++.h>
#define lli long long int
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int a, arr[20002]; cin>>a;
	
	int num=0, cur=1;
	for(int i=0; i<a; i++){
		int b; cin>>b;
		if(b==cur){
			num++;
			cur++;
		}
	}
	
	if(num) cout<<a-num<<endl;
	else cout<<"-1"<<endl;

	return 0;
}
