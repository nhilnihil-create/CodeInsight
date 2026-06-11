#include<bits/stdc++.h>


using namespace std;

int H,W,A,B;

int main() {
	
	cin>>H>>W>>A>>B;
	
	int val = 0;
	
	for(int i=0; i<H;i++){
		if(i==B) val=1;
		for(int j=0; j<W;j++){
			if(j<A) cout<<val;
			else cout<<1-val;
		}
		cout<<"\n";
	}
	
	return 0;
}