#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6+5;
int main() {
	std::vector<int> V(10);
	for(int i=1;i<=5;i++) {
		cin>>V[i];    
		if(V[i]==0) cout<<i<<endl;
	}
    return 0;
}