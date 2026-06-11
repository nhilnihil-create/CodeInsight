#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double avg;
	int s[1000];
	double ss;
	while(1){
		cin >> n;
		if(n == 0) break;
		avg = 0;
		for(int i = 0;i < n;i++){
			cin >> s[i];	
			avg +=s[i];
		}
		
	    avg /= n;
		ss = 0;
		for(int i = 0;i < n;i++){
			ss += (s[i] - avg) * (s[i] - avg);
		}
		
		ss /= n;
		
		printf("%4lf\n",sqrt(ss));
	}
	return 0;
}