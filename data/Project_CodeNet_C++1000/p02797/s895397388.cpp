#include<bits/stdc++.h>
using namespace std;


bool inside(int i, int j, int h, int w) {
	return (i >= 0 && i < h && j >= 0 && j < w);
	}

int main() {

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
	int n,k,s;
	cin>>n>>k>>s;
	if(s < 1e9) {
		for(int i = 0; i < n; i++) {
			if(k-- > 0) 
				cout<<s<<" ";
			else
				cout<<s+1<<" ";
		}
	}
	else {
		for(int i = 0; i < n; i++) {
			if(k-- > 0) 
				cout<<s<<" ";
			else
				cout<<1<<" ";
		}
	}

	return 0;		
}
