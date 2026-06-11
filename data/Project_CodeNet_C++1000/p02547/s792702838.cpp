#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<vector<int>> arr(n,vector<int>(2));

	for(int i=0;i<n;i++){
		cin>>arr[i][0]>>arr[i][1];
	}

	int count = 0;

	for(int i=0;i<n;i++){
		if(arr[i][0]==arr[i][1]){
			count++;
			if(count >= 3){
                                cout<<"Yes";
                                return 0;
                        }
		}
		else{
			if(count >= 3){
				cout<<"Yes";
				return 0;
			}

			count = 0;
		}
	}

	cout<<"No";

	return 0;

}
