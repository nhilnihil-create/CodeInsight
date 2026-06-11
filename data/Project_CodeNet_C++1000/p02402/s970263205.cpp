
#include<iostream>
int main(){
	int n,a[10000];
	int na = -1000001,nb = 1000001;
	long long sum = 0;
	std::cin>>n;
	for(int i = 0; i < n; ++i){
		std::cin>>a[i];
		if(na < a[i])
			na = a[i];
		if(nb > a[i])
			nb = a[i];
		sum += a[i];
	}
	std::cout<<nb<<" "<<na<<" "<<sum<<std::endl;
	return 0;
}