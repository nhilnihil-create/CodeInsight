#include <bits/stdc++.h>
using namespace std;

/*
obv first would be greatest
always best to expand the biggest
note that *strictly less* is the important part

can we just do it by looking?
feel that blocks disrupt order...
we fail iff at some point someone can't 

can we just sim this?
p: finding next less that is < (we can just compress)
*/

int main(){
	int n;
	cin >> n;
	int sz = 1 << n;
	vector<int> v(sz);
	for(int i = 0;i < sz; ++i){
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	vector<int> cmp;
	for(int i = 0;i < sz; ++i){
		if(i && v[i-1] == v[i]){
			cmp.back()++;
		}
		else{
			cmp.push_back(1);
		}
	}
	vector<int> cnt(cmp.size());
	++cnt.back();
	--cmp.back();
	bool ans = true;
	for(int it = 0; it < n; ++it){
		vector<int> add(cmp.size(), 0);
		for(int i = cmp.size()-1;i > 0; --i){
			while(cnt[i] & cmp[i-1] 	== 0){
				cnt[i-1] += cnt[i];
				cnt[i] = 0;
			}
		}
		for(int i = cmp.size()-1;i > 0; --i){
			if(cmp[i-1] > cnt[i]){
				cmp[i-1] -= cnt[i];	
				add[i-1] += cnt[i];
			}
			else{
				int left = cnt[i] - cmp[i-1];
				add[i-1] += cmp[i-1];
				cmp[i-1] = 0;	
				cnt[i] -= left;
				cnt[i-1] += left;
			}
		}
		for(int i = 0;i < add.size(); ++i){
			cnt[i] += add[i];
		}
	}
	int sum = accumulate(cmp.begin(), cmp.end(), 0);
	cout << (sum == 0?"Yes":"No") << '\n';
}
