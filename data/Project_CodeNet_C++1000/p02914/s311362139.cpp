#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	vector<long long> arr(n);
	for(int i=0;i<n;++i)cin>>arr[i];

	long long all = 0L;
	for(int i=0;i<n;++i)all ^= arr[i];
	//cout<<all<<endl;
  
    
	for(int i=0;i<n;++i){
		for(int bit=0;bit<60;++bit){
			if( (all & (1LL<<bit)) && ((1LL<<bit) & arr[i]) ){
				arr[i] -= (1LL<<bit);
			}
		}
	}
  
  	long long sum = 0L;
	for(int i=0;i<n;++i)sum ^= arr[i];
	//cout<<all<<endl;
  
	int index = 0;
	for(int bit=59;bit>=0;--bit){
		long long mx = -1;
		int id = index; 
		for(int i=index;i<n;++i){
			if( ((1LL<<bit)&arr[i])){
				id = i;
				mx = arr[i];
                break;
			}
		}
		if(mx==-1){continue;}
		swap(arr[index],arr[id]);

		for(int i=0;i<n;++i){
			if(i!=index && arr[i]&(1LL<<bit) ){
				arr[i] ^= arr[index];
			}
		}
		index++;
        //for(auto i:arr)cout<<i<<" ";cout<<endl;
	}
  
	
	long long curr = 0L;
	for(int i=0;i<n;++i){
		curr ^= arr[i];
	}
	
	cout<<curr + (curr^sum) + all<<endl;
	return 0;
}