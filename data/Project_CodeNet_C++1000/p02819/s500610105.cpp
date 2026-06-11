#include <iostream>
#include <vector>

using namespace std;

int main(){

	int x;
	cin>>x;
	vector<int> pr;
	int a[200000];
	for(int i=2;i<200000;i++){
	
		a[i]=0;
	}
	for(int i=2;i<200000;i++){

		if(a[i]==0){

			if(i*i<=200000){
			for(int j=i*i;j<200000;j+=i){
			
				a[j]=1;
			}
			}
			else{
			
				break;
			}
		}
	}

	for(int i=2;i<200000;i++){	

		if(a[i]==0){

			pr.push_back(i);
		}
	}

	int l=0,r=pr.size();
	int mid;
	while(l<=r){
	
		mid=l+(r-l)/2;
		if(pr[mid]==x){
		
			cout<<x<<'\n';
			return 0;
		}
		else if(pr[mid]>x){
		
			r=mid-1;
		}
		else{
		
			l=mid+1;
		}
	}
	cout<<pr[r+1]<<'\n';
	return 0;

}
