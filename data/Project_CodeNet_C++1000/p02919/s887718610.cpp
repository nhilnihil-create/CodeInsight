#include <bits/stdc++.h>
using namespace std;
#define int long long int

main() {
	int n;
	cin>>n;
	int arr[n];
	int pos[n+1];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		pos[arr[i]]=i;
	}
	set<int>s;
	int ans=0;
	
	for(int i=n; i>=1; i--){
		int position=pos[i];
		if(s.size()==0){
			s.insert(pos[i]);
			continue;
		}
		auto it=s.begin();
		int valf=(*it);
		it=s.end();
		it--;
		int vall=(*it);
		if(position<valf){
			auto it=s.begin();
			int fir=(*it);
			int las=n;
			it++;
			if(it!=s.end()){
				las=(*it);
			}
			ans+=(position+1)*(las-fir)*i;
			s.insert(position);
			continue;
		}
		if(position>vall){
			auto it=s.end();
			it--;
			int fir=(*it);
			int las=-1;
			if(it!=s.begin()){
				it--;
				las=(*it);
			}
			ans+=(n-position)*(fir-las)*i;
			s.insert(position);
			continue;
		}
		it=s.lower_bound(position);
		int afir=(*it);
		it++;
		int asec=n;
		if(it!=s.end()){
			asec=(*it);
		}
		it--;
		it--;
		int bfir=(*it);
		int bsec=-1;
		if(it!=s.begin()){
			it--;
			bsec=(*it);
		}
		s.insert(position);
		ans+=(asec-afir)*(position-bfir)*i;
		ans+=(bfir-bsec)*(afir-position)*i;
	}
	cout<<ans;
	return 0;
}