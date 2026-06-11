#include<iostream>
int main() {
	int w,h;
	while (true){
	std::cin >> w >> h;
	if(w==0 && h==0){break;}
	int wc=1;
	int hc=1;
	while(wc<=w){
		while(hc<=h){
			if(wc==1 || wc==w || hc==1 || hc==h){
			std::cout << "#";}else{
				std::cout << ".";
			}
			hc++;
		}
		hc=1;
		std::cout << std::endl;
		wc++;
	}
	std::cout << std::endl;
}
	return 0;
}