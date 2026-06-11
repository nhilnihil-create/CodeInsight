#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

long long nCr(const long long n, long long r) {

	if (n == 0) { return 0; }
	if (r == 0) { return 1; }
	if (r == 1) { return n; }
	if (n == r) { return 1; }
	if(n<r)     { return 0;}
	if (r > n / 2) { r = n / 2; }

	double result = 1;
	for (double i = 1; i <= r; i++) {
		result *= (n - i + 1) / i;
	}

	return(result);
}


int main(){
	long long N; cin>>N;
  	map <long long,long long> mp;
  	int A[N];
  	for(int i=0; i<N; i++){
      int a;
      cin>>a;
      mp[a]++;
      A[i]=a;
    }
  	long long res=0;
  	for(auto itr=mp.begin(); itr!=mp.end(); itr++) res+=nCr(itr->second,2);
  		
    for(int i=0; i<N; i++){
      long long after=nCr(mp[A[i]]-1,2);
      long long before=nCr(mp[A[i]],2);   
      cout<<res-(before-after)<<endl;
      //cout<<before<<" "<<after<<endl;
      //cout<<mp[A[i]]-1<<endl;
     	//cout<<res<<" "<<before<< " "<<after<<endl;
    }
}
                  
  
  
  
  
  
  
  
  
  
  
   
