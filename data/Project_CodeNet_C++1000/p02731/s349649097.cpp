#include <iostream>

using namespace std;

int main(){
	int l;
	cin >> l;
	
	double height, width, depth;
	
	height = width = depth = (double)l / 3.0;
	
	printf("%.10f\n", height*width*depth);
	
}