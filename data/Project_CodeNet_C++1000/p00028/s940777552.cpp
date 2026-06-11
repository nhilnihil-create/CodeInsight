#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int z[101];
	int i, mode;
	
	for(int j = 0; j < 101; j++) z[j] = 0;
	
	while((scanf("%d", &i)) != EOF) z[i]++;
	
	mode = 0;
	for(int j = 1; j < 101; j++) mode = max(mode, z[j]);
	
	for(int j = 1; j < 101; j++){
		if(z[j] == mode) printf("%d\n", j);
	}
	
	return 0;
}