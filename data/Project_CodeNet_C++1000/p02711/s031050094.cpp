#include <stdio.h>
int main() {
	
	int num, fnt, mdl, bck;
	scanf("%d", &num);
	
	fnt = num / 100;
	mdl = num / 10 % 10;
	bck = num % 100 % 10;
	
	if (fnt != 7){
		if (mdl != 7){
			if (bck != 7){
				printf("No");
			}
			else printf("Yes");
		}
		else printf("Yes");
	}
	else printf("Yes");

	
	return 0;
}