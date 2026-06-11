#include <stdio.h>

	int main () {
		int mons;
		int serv;
		
		scanf("%i", &mons, 1 < mons < 10*10*10*10);
		scanf("%i", &serv, 1 < serv < 10*10*10*10);
		
		int kill;
		kill = mons/serv;
		
		if (mons%serv > 0){
		kill++;
		}
		
		printf("%i", kill);
		
		return 0;
	}