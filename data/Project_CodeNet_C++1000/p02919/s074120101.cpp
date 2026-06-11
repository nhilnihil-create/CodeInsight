#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;cin>>n;
    vector<int> p(n+1);
    for(int i = 0; i < n ; i++){
        int t;cin>>t;t--;
        p[t] = i;
    }

	set<int> s;
	long long ans = 0;
	for(int i = n-1; i>=0; i--){
		s.insert(p[i]);
		vector<int> l(2,-1);
		vector<int> r(2,n);
		auto it = s.find(p[i]);
		for(int j = 0; j < 2; j++){
			if(it == s.begin()) break;
			--it;
			l[j] = *it;
		}
        auto it1 = s.find(p[i]);
		for(int j = 0; j < 2; j++){
            ++it1;
			if(it1 == s.end()) break;
			r[j] = *it1;				
		}
        ll c = 0;
		c = (ll)(l[0]-l[1])*(ll)(r[0]-p[i])+(ll)(p[i]-l[0])*(ll)(r[1]-r[0]);
            it++;
		ans+=c*(i+1);
	}	
   
	cout<<ans;
}
