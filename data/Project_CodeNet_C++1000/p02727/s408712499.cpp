#include<bits/stdc++.h>
using namespace std;

//#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

#define LL long long

int main() {
	int x,y,a,b,c;
	vector<int> A;
	vector<int> B;
	vector<int> C;
	cin >> x >> y;
	cin >> a >> b >> c;

	int num;
	for(int i=0;i<a;i++) {
		cin >> num;
		A.push_back(num);
	}
	for(int i=0;i<b;i++) {
		cin >> num;
		B.push_back(num);
	}
	for(int i=0;i<c;i++) {
		cin >> num;
		C.push_back(num);
	}

	sort(A.begin(), A.end(), greater<int>());
	sort(B.begin(), B.end(), greater<int>());
	sort(C.begin(), C.end(), greater<int>());

	vector<int> ans;
	for(int i=0;i<x;i++) {
		ans.push_back(A[i]);
	}
	for(int i=0;i<y;i++) {
		ans.push_back(B[i]);
	}
	sort(ans.begin(), ans.end());

	int st = 0;
	for(int i=0;i<C.size();i++) {
		if(st >= x+y) break;
		if(C[i] > ans[st]) {
			ans[st] = C[i];
			st++;
		}
	}

	LL sum = 0;
	for(int i=0;i<ans.size();i++) {
		sum += 1LL * ans[i];
	}

	cout << sum << endl;

	return 0;
}
