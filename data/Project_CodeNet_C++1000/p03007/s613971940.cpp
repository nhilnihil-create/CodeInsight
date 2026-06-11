#include <bits/stdc++.h>

using namespace std;

int main(){
	int n; cin >> n;
	int sum=0;
	vector<int> pos,neg;
	for(int i=0,a;i<n;i++){
		cin >> a;
		sum+=abs(a);
		if(a>=0){
			pos.push_back(abs(a));
		}
		else{
			neg.push_back(abs(a));
		}
	}
	sort(pos.begin(),pos.end());
	sort(neg.begin(),neg.end());
	if(pos.size()==0){
		cout << sum-2*neg[0] << endl;
		int cv=-neg[0];
		for(int i=1;i<n;i++){
			cout << cv << " " << -neg[i] << endl;
			cv=cv+neg[i];
		}
	}
	else if(neg.size()==0){
		cout << sum-2*pos[0] << endl;
		int cv=pos[0];
		for(int i=1;i<n-1;i++){
			cout << cv << " " << pos[i] << endl;
			cv=cv-pos[i];
		}
		cout << pos[n-1] << " " << cv << endl;
	}
	else if(neg.size()==1){
		cout << sum << endl;
		int cv=-neg[0];
		for(int i=0;i<n-2;i++){
			cout << cv << " " << pos[i] << endl;
			cv=cv-pos[i];
		}
		cout << pos[n-2] << " " << cv << endl;
	}
	else if(pos.size()==1){
		cout << sum << endl;
		int cv=pos[0];
		for(int i=0;i<n-1;i++){
			cout << cv << " " << -neg[i] << endl;
			cv=cv+neg[i];
		}
	}
	else {
		cout << sum  << endl;
		int cv=-neg[0];
		for(int i=1;i<pos.size();i++){
			cout << cv << " " << pos[i] << endl;
			cv=cv-pos[i];
		}
		
		int cva=pos[0];
		for(int i=1;i<neg.size();i++){
			cout << cva << " " << -neg[i] << endl;
			cva=cva+neg[i];
		}
		cout << cva << " " << cv << endl;
	}
	return 0;
}