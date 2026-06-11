#include<iostream>

using namespace std;

	
long long bin(long long table[],long long value,long long low,long long high){
		
		long long upper_bound = high;
	
		while(low<=high){
			long long mid = (low+high)/2;
			if(table[mid]>value){
				high = mid-1;
				
			}
			else if(table[mid]<value){
				low = mid+1;
				
			}
			else{
				return mid;
			}
			//printf("%d %d\n",checker1,checker2);

			
		}
		
		if(low>=upper_bound)return upper_bound-1;
		else return low-1;

		
		
return -1;
}


int main(){
	long long n,m,k; 
	scanf("%lli %lli %lli",&n,&m,&k);

	long long *table1 = new long long [n+1];
	long long *table2 = new long long [m+1];

	table1[0] =0;
	for(int i=1;i<=n;i++){
		cin >> table1[i];
		table1[i] += table1[i-1];
	}

	table2[0] = 0;
	for(int i=1;i<=m;i++){
		cin >> table2[i];
		table2[i] += table2[i-1];
	}


	long long count = 0;
	for(int i=0;i<n+1;i++){
		long long rem = k - table1[i];

		if(rem<0)continue;
		long long j = bin(table2,rem,0,m);
		
	//	printf("%lli %lli %d\n",rem,j,i);
		count = max(count,(i+j));
	}

printf("%lli\n",count);


	return 0;
}