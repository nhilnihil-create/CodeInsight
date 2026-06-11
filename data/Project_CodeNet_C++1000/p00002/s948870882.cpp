
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);

	int a,b;
	while( scanf("%d%d",&a,&b) != -1 ) {
		stringstream s;
		s << (a+b);
		cout << s.str().length() << endl;
	}

	//while(1){}
	return 0;
}