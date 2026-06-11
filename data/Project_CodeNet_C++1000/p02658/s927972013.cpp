#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define ret return
using namespace std;
int main() {
	int n;cin>>n;
	ll seq[n];
	memset(seq,0ll, sizeof(seq));
	ll num;
	for(int i=0;i<n;i++){
		cin>>num;
		if(num==0ll) {
			cout<<0<<endl;
			ret 0;
		}
		seq[i]=num;
		
	}
	ll product=seq[0];
	for(int i=1;i<n;i++){
		if(1000000000000000000ll / product < seq[i]){
			cout<<-1<<endl;
			ret 0;
		}
		product*=seq[i];
	}
	cout<<product<<endl;
	ret 0;
}

