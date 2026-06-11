    //============================================================================
    // Name        : f.cpp
    // Author      :
    // Version     :
    // Copyright   : Your copyright notice
    // Description : Hello World in C++, Ansi-style
    //============================================================================
     
    #include <iostream>
    #include<vector>
    using namespace std;
     
    int main() {
    	long long n;cin>>n;
    	if(n==2){
    		cout<<1<<endl;
          return 0;
    	}
    	int mans=0;
    	for(long long i=1;i*i<=n-1;i++){
    		if((n-1)%i==0){
    			mans+=2;
    			if(i*i==n-1){
    				mans--;
    			}
    		}
    	}
    	mans--;
    	vector<long long> v;
    	v.push_back(n);
    	for(long long i=2;i*i<=n;i++){
    		if(n%i==0){
    			v.push_back(i);
    			if(i*i!=n){
    				v.push_back(n/i);
    			}
    		}
    	}
    	int nans=0;
    	for(int i=0;i<v.size();i++){
    		long long tempn=n;
    		long long tempk=v[i];
    		while(tempn>=tempk){
    			if(tempn%tempk==0){
    				tempn/=tempk;
    			}else{
    				tempn%=tempk;
    			}
     
    		}
    		if(tempn==1)nans++;
    	}
    	cout<<mans+nans<<endl;
    	return 0;
    }