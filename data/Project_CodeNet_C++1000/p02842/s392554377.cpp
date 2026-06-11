#include <bits/stdc++.h>
using namespace std;
int main() {
	// #ifndef ONLINE_JUDGE
	// 	// for getting input from input.txt
	// 	freopen("input.txt", "r", stdin);
	// 	// for writing output to output.txt
	// 	freopen("output.txt", "w", stdout);
	// #endif

		double n;
		cin>>n;
		for(int i=0;i<50000;i++){
			int x = i*1.08;
			if(n == x){
				cout<<i<<"\n";
				return 0;
			}
		}

		 cout << ":(" << endl;
		return 0;
	}	