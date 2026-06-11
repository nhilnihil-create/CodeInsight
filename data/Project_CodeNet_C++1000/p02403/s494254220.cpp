#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int h, w;
	while(true) {
		cin>>h>>w;
		if(h==0&&w==0) break;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cout<<'#';
			}
			cout<<'\n';
		}
		cout<<'\n';
	}
	return 0;
}

