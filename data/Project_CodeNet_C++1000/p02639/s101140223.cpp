#include<bits/stdc++.h>
#define mod7 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int val, v;
	for (int i=0; i<5; i++) {
		cin>>val;
		if (val==0) v = i+1;
	}
	cout<<v<<'\n';
}

