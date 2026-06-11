#include<stdio.h>

int main(){
  char cd;
  int i,j,n,rank;
  int card[4][13];
  char buf[512];
  for(i=0;i<4;i++){
    for(j=0;j<13;j++){
      card[i][j] = 0;
    }
  }
  fgets(buf,512,stdin);
  sscanf(buf, "%d",&n);
  for(i=0;i<n;i++){
    fgets(buf, 512, stdin);
    sscanf(buf, "%c %d", &cd, &rank);
    switch(cd){
    case 'S':
      card[0][rank-1] = 1;
      break;

    case 'H':
      card[1][rank-1] = 1;
      break;

    case 'C':
      card[2][rank-1] = 1;
      break;

    case 'D':
      card[3][rank-1] = 1;
      break;
    }
  }

  for(i=0;i<4;i++){
    for(j=0;j<13;j++){
      if(card[i][j] == 0){
	switch(i){
	case 0:
	  printf("S %d\n",j+1);
	  break;

	case 1:
	  printf("H %d\n",j+1);
	  break;

	case 2:
	  printf("C %d\n",j+1);
	  break;

	case 3:
	  printf("D %d\n",j+1);
	  break;
	}
      }
    }
  }
  return 0;
}