#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int		main(){
	char S[200001];
	// char *S;
	// S = (char *)calloc(30000, sizeof(char));
	scanf("%s\n", S);
	// S[strlen(S)] = '\0';
	char prev = ' ';
	int cnt = 0;
	int flag = 0;
	for (int i  = 0; i < strlen(S); i++){
		// printf("%s\n", prev);
		if (flag == 1 || S[i] != prev)
			flag = 0;
		else if (i == strlen(S) - 1) cnt--;
		else {
			flag = 1;
			i++;
		}
		prev = S[i];
		cnt++;
	}
	printf("%d\n", cnt);
	return (0);
}

// int		main(){
// 	char S[10001];
// 	scanf("%s\n", S);
// 	S[strlen(S)] = '\0';
// 	char prev[10001];
// 	// printf("%s\n", S);
// 	int cnt = 0;
// 	for (int i  = 0; i < strlen(S); i++){
// 		// printf("%s\n", prev);
// 		cnt++;
// 		prev[0] = S[i];
// 		if (strlen(prev) > 1 || S[i] != prev[0])
// 			prev[1] = '\0';
// 		else if (i != strlen(S) - 1){
// 			prev[1] = S[++i];
// 			prev[2] = '\0';
// 		}
// 	}
// 	printf("%d\n", cnt);
// 	return (0);
// }

// if (strlen(prev) > 1 || S[i] != prev[0]){
// 			cnt++;
// 			prev[0] = S[i];
// 			prev[1] = '\0';
// 		}
// 		else if (i == strlen(S) - 1) break ;
// 		else {
// 			cnt++;
// 			prev[0] = S[i];
// 			prev[1] = S[++i];
// 			prev[2] = '\0';
// 		}
// 	}