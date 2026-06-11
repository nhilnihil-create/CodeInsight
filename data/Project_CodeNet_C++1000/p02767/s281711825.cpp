#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++) cin>>a[i];

	int min_ans = INT_MAX;
	sort(a,a+n);

	int start = a[0];
	int end = a[n-1];

	for(int i = start ; i <= end ; i++){
		int curr = i;
		int temp = 0;
		for(int i = 0;i<n;i++){
			temp += abs(a[i] - curr) * abs(a[i] - curr) ;
		}
		if(temp < min_ans){
			min_ans = temp ;
			
		}
	}
	cout<<min_ans<<endl;
}