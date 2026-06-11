#include <iostream>

int main()
{
	int H, W;
	
	while (1) {
		std::cin >> H >> W;
		if (H == 0 && W == 0) {
			break;
		}
		for (int i=0;i < H;i++) {
	for(int n=0;n<W;n++){
		std::cout << "#";
				}
	std::cout << std::endl;
			}
		std::cout <<std::endl;
	}
    return 0;
}