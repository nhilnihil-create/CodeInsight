#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<long long>A;
	for(int i=0;i<N;i++){
		int a;
		cin>>a;
		A.push_back(a);
	}
	sort(A.begin(),A.end());
	vector<long long>minus;
	vector<long long>plus;
	minus.push_back(A[0]);
	plus.push_back(A[N-1]);
	for(int i=1;i<N-1;i++){
		if(A[i]<0){
			minus.push_back(A[i]);
		}else{
			plus.push_back(A[i]);
		}
	}
	sort(minus.begin(),minus.end());
	sort(plus.begin(),plus.end());
	vector<pair<long long,long long> >ans;
	for(int i=0;i<plus.size()-1;i++){
		ans.push_back(make_pair(minus[0],plus[i]));
		minus[0]-=plus[i];
	}
	for(int i=0;i<minus.size();i++){
		ans.push_back(make_pair(plus[plus.size()-1],minus[i]));
		plus[plus.size()-1]-=minus[i];
	}
	cout<<plus[plus.size()-1]<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<ans[i].first;
		cout<<" ";
		cout<<ans[i].second<<endl;
	}
}
	