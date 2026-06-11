#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(void){
	
	int n,j,sum,max1;
		
	while(cin>>n,n){
		
		vector<int> v;
		
		for(int i=0;i<n;i++){
			cin>>j;
			v.push_back(j);
		}
		max1=v[0];

		for(int i=0;i<n;i++){
				sum=0;
			for(int j=i;j<n;j++){
				sum=sum+v[j];
				max1=max(max1,sum);
			}
		}
		cout<<max1<<endl;
		

	}
}