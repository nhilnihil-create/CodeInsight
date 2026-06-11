#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
using namespace std;
int main()
{
	int N,ANS=0;
	cin >> N;

	for(int i=1;i<(N/2)+1;i++){
		if(i!=N-i&&i<N-i){
			ANS++;
		}
	}
	cout << ANS << endl;
}