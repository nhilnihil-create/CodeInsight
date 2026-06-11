#include <bits/stdc++.h>

int main(int argc,char **argv){
	int n,k;
	std::cin>>n>>k;
	if(k==1) std::cout<<'0';
	else std::cout<<n-k;
	std::cout<<'\n';
	return 0;
}
