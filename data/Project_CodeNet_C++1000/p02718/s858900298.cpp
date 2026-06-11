#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> n;

int main(){
	int n,m,t,cnt=0;
	double al=0;
	vector <int> a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t;
		al+=t;
		a.push_back(t);
	}
	al/=4*m;
	sort(a.begin(),a.end());
	for(int i=0;i<n;i++){
		if(a[i]>=al){
			cnt++;
		}
	}
	if(cnt>=m){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}
