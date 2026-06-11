#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> cnt(101,0);
	for(int i; cin>>i;){
		cnt[i]++;
	}
	int max = 0;
	vector<int> ans;
	for(int i=1; i<101; i++){
		if(cnt[i] > max){
			max = cnt[i];
			ans.clear();
			ans.push_back(i);
		}else if(cnt[i] == max){
			ans.push_back(i);
		}
	}
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i]<<endl;
	}
}