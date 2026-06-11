#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin>>N;
	int A,B;
	int count = 0;
	bool flag = false;
	while(N--){
		cin>>A>>B;
		if(A==B){
			count +=1;
			if(count == 3){
				flag = true;
			}
		}
		if(A != B)
			count = 0;
	}
	if(flag)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

}