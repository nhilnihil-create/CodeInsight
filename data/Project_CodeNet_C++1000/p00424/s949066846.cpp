#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
	int n, *a;
	char *w, tmp, tmp2;
	
	while(1){
		cin >> n;
		if(n == 0){
			break;
		}
		a = (int *)calloc(130, sizeof(int));
		w = (char *)calloc(n+1, sizeof(char));
		for(int i = 1; i <= n; i++){
			cin >> tmp >> tmp2;
			a[(int)(tmp)] = i;
			w[i] = tmp2;
		}
		cin >> n;
		
		for(int i = 0; i < n; i++){
			cin >> tmp;
			if(a[(int)(tmp)] != 0){
				cout << w[a[(int)(tmp)]];
			} else {
				cout << tmp;
			}
		}
		cout << endl;
		
		free(a);
		free(w);
	}
	
	
	return 0;
}