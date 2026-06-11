#include <iostream>
#include <stdlib.h>

using namespace std;

int func(int **a, int h, int w, int s, int t)
{
	int c = 0;
	if(t == h || w == s || a[t][s] == -1){
		return 0;
	} else if(a[t][s] == 1){
		return 1;
	}

	return func(a, h, w, s+1, t) + func(a, h, w, s, t+1);
}

int main(int argc, char **argv)
{
	int h, w, **a, n, s, t;
	
	while(1){
		cin >> w >> h;
		if(w == 0){
			break;
		}
		a = (int **)calloc(h, sizeof(int));
		for(int i = 0; i < h; i++){
			a[i] = (int *)calloc(w, sizeof(int));
		}
		a[h-1][w-1] = 1;
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> s >> t;
			
			a[t-1][s-1] = -1;
		}
		
		cout << func(a, h, w, 0, 0) << endl;
		
		for(int i = 0; i < h; i++){
			free(a[i]);
		}
		free(a);
	}
	
	return 0;
}