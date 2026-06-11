#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	vector<int> ans(N-1,0);
	int l=1;
	for(int i=0;i<N-1;i++){
		if(ans[i]>0)continue;
		int p=(int)pow(2,l);
		for(int k=i;k<N-1;k+=p)ans[k]=l;
		l++;
	}
	
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			if(j==N-1)cout << ans[j-i-1] << endl;
			else cout << ans[j-i-1] << " ";
		}
	}
	
	return 0;
}