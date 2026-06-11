#include <stdio.h>
#include <string.h>
//subgoals
//1. scan semua input
//2. cari jumlah AC,WA,TLE,RE

int main (){
	int N, AC=0, WA=0,TLE=0, RE=0;
	scanf ("%d",&N);
	
	for (int i=0; i<N;i++){
	
	char str [255];
	scanf ("%s",str);
	
	if (strcmp(str,"AC")==0){//"AC" - "AC"=0
		AC++;
	}else if (strcmp(str,"WA")==0){ //if str is WA
		WA++;
	}else if (strcmp(str,"TLE")==0){//if str is TLE
		TLE++;
	}else if (strcmp(str,"RE")==0){//if str i RE
 		RE++;
	}
}
	printf ("AC x %d\n ",AC);
	printf ("WA x %d\n ",WA);
	printf ("TLE x %d\n ",TLE);
	printf ("RE x %d\n ",RE);
	return 0;
}