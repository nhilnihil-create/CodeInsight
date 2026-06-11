#include<bits/stdc++.h>
using namespace std;

long long n,tmp;
vector<int> tmp1;
multiset<int> v;
multiset<int> s;

int main(){

	cin>>n;

	for(int i=0;i<(1<<n);i++){
		cin>>tmp;
		s.insert(-tmp);
	}
	
	v.insert(*s.begin());
	s.erase(s.begin());
	
	while(s.size()>0){
		for(auto i:v){
			auto p=s.upper_bound(i);
			if(p==s.end()){
				cout<<"No"<<endl;
				return 0;
			}
			tmp1.push_back(*p);
			s.erase(p);
		}
		
		for(int i=0;i<tmp1.size();i++){
			v.insert(tmp1[i]);
		}
		tmp1.clear();
	}
	
	cout<<"Yes"<<endl;

return 0;
}
