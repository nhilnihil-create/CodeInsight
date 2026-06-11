#include <iostream>
#include <vector>
#include <algorithm>

#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(int argc, char **argv){
	int n = 0;
	double x1, y1, x2, y2, x3, y3, x4, y4;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
#endif

//#if INPUT_FROM_FILE
//	ifs >> n;
//#else
//	std::cin >> n;
//#endif
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
#if INPUT_FROM_FILE
		ifs >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
#else
		scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		//std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
#endif

		//if(x2 - x1 == 0 && x4 - x3 == 0){
		//	std::cout << "YES" << std::endl;
		//}
		//else if(x2 - x1 == 0 || x4 - x3 == 0){
		//	std::cout << "NO" << std::endl;
		//}
		//else{
		//	double a0 = (y2 - y1) / (x2 - x1);
		//	double a1 = (y4 - y3) / (x4 - x3);

		//	if(a0 == a1){
		//		std::cout << "YES" << std::endl;
		//	}
		//	else{
		//		std::cout << "NO" << std::endl;
		//	}
		//}

		if(fabs((y2 - y1)*(x4 - x3) - (y4 - y3)*(x2 - x1)) < 0.0000000001){
			std::cout << "YES" << std::endl;
		}
		else{
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}
