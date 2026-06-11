#include <cstdio>
#include <iostream>

inline int counter(int n);

int main(){
	std::ios::sync_with_stdio(false);
	int data[50],n,i=0;
	while(std::cin){
		std::cin >> n;
		data[i] = counter(n);
		i++;
	}
	for (int j=0;j<i-1;j++){
		std::cout << data[j] << "\n";
	}
}

inline int counter(int n){
	int count=0;
	for (int i=0;i<10;++i){
		for (int j=0;j<10;++j){
			for (int l=0;l<10;++l){
				for (int t=0;t<10;++t){
					if (i+j+l+t == n){
						count++;
					}
				}
			}
		}
	}
	return count;
}