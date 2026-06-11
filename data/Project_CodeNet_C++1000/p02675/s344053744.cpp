#include<bits/stdc++.h>
#define mod7 1000000007

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	switch(n%10) {
		case 0:
		case 1:
		case 6:
		case 8: cout<<"pon\n";
			break;
		case 2:
		case 4:
		case 5:
		case 7:
		case 9: cout<<"hon\n";
			break;
		case 3: cout<<"bon\n";
			break;
	}
}

