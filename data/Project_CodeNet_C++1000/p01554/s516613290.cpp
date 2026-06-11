#include <stdio.h>

#define MYSCAN scanf

char u[300][20];
int n;

int match(char t[20]);

int main(void){
	int i;
	int m;
	int mat;
	char t[20];
	int door = -1;

	MYSCAN("%d", &n);
	MYSCAN("\n");
	// テァツ卍サテゥツ個イIDテ」ツ?ョテ・ツ?・テ・ツ環?
	for (i = 0; i < n; i++){
		gets(u[i]);
	}

	MYSCAN("%d", &m);
	MYSCAN("\n");
	for (i = 0; i < m; i++){
		// テ」ツつォテ」ツδシテ」ツδ嘉」ツつ津」ツ?凝」ツ?姪」ツ??
		gets(t);
		mat = match(t);
		// テァツ卍サテゥツ個イテ」ツ?陛」ツつ古」ツ?ヲテ」ツ?ェテ」ツ?凝」ツ?」テ」ツ?淌」ツつ?
		if (mat == -1){
			printf("Unknown %s\n", t);
		}
		else{
			// テ」ツδ嘉」ツつ「テ」ツ?古ゥツ鳴嘉」ツ?セテ」ツ?」テ」ツ?ヲテ」ツ?淌」ツつ嘉」ツ?づ」ツ?妥」ツつ?
			if (door == -1){
				printf("Opened by %s\n", t);
			}
			// テゥツ鳴凝」ツ??」ツ?ヲテ」ツ?淌」ツつ嘉ゥツ鳴嘉」ツつ?」ツつ?
			else{
				printf("Closed by %s\n", t);
			}
			door *= -1;
		}
	}


	return 0;
}


// テヲツ鳴?・ツュツ療・ツ按療」ツ?古」ツ?づ」ツ?」テ」ツ?ヲテ」ツつ凝」ツ?凝」ツ?ゥテ」ツ??」ツ?凝」ツつ津・ツ按、テ・ツョツ堙」ツ?凖」ツつ凝ゥツ鳴「テヲツ閉ー
// テ・ツ青暗ィツ?エテ」ツ?凖」ツつ凝ヲツ鳴?・ツュツ療・ツ按療」ツ?古」ツ?ェテ」ツ?妥」ツつ古」ツ?ー-1テ」ツつ津ィツソツ氾」ツ??
int match(char t[20]){
	int i, j;

	for (i = 0; i < n; i++){
		for (j = 0; t[j] != '\0' && u[i][j] != '\0'; j++){
			if (t[j] != u[i][j]){ break; }
		}
		if (t[j] == '\0' && u[i][j] == '\0'){
			return i;
		}
	}
	return -1;
}