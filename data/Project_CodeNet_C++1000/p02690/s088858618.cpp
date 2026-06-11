#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin>>x;
	for(int i=-10;i<1000;i++){
		for(int j=-80;j<1000;j++){
			if(pow(i,5)-pow(j,5)==x) {
				cout<<i<<" "<<j<<endl;return 0;
			}
		}
	}
	return 0;
}
