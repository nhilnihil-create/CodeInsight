#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<ctime>
using namespace std;
int main(){
	long long k;
	int a[35]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 
	1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
	while(cin>>k){
		k%=32;
		if(k==0) k=32;
		cout<<a[k-1]<<endl;
	}
	return 0;
}
