#include<iostream>

int main(void){
	int a, b, c, d;
	int W, H, x, y, r;
	
	std::cin >> W >> H >> x >> y >> r;
	
	/*まず円の4点の構成要素を計算*/
	a = x - r;
	b = x + r;
	c = y - r;
	d = y + r;
	
	if (0 <= a && b <= W && 0 <= c && d <= H ) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
	
	return 0;
}