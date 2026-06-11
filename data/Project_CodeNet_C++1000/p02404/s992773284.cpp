#include <bits/stdc++.h>
using namespace std;

int main()
{
	int h,w;

	while(1){
		cin>>h>>w;

		if(h==0)
			break;

		else{
			for(int i=1; i<=w; i++)
				cout<<'#';
			cout<<endl;
			for(int i=1; i<=h-2; i++){
				cout<<'#';
				for(int j=1; j<=w-2; j++)
					cout<<'.';
				cout<<'#';
				cout<<endl;
			}
			for(int i=1; i<=w; i++)
				cout<<'#';
			cout<<endl;
			cout<<endl;
		}
	}
	return 0;
}