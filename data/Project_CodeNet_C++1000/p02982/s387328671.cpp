#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > arr;

int main(){
	int n,d;
	cin>>n>>d;
	for(int i=0;i<n;i++){
		vector<int> v;
		for(int j=0;j<d;j++){
			int x;
			cin>>x;
			v.push_back(x);
		}
		arr.push_back(v);
	}
	int ans=0;
	for(int k=0;k<n;k++){
		for(int q=k+1;q<n;q++){
			double sum=0;
			for(int z=0;z<d;z++){
				sum+=pow(abs(arr[k][z]-arr[q][z]), 2);
			}
			sum=sqrt(sum);
			if(floor(sum)==ceil(sum))ans++;
		}
	}
	cout<<ans;
}