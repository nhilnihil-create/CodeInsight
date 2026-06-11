#include<bits/stdc++.h>
 
int main() {
	int n, count=0;
	std::cin>>n;
	int* ara = new int[n]; 
	int* arb = new int[n];
 
	for(int i=0; i<n; i++){
        std::cin>>ara[i];
        arb[i]=ara[i];
    }
 
	std::sort(ara, ara+n);
 
	for(int i=0; i<n; i++) if(ara[i]!=arb[i]) count++;
 
	if(count==2 || count==0) std::cout<<"YES";
	else std::cout<<"NO";
}