
int N, M, P;
int xi[100], xsum;

int main(){
	int i;
	int result;
	while(1){
		scanf("%d%d%d", &N, &M, &P);
		if(N == 0 && M == 0 && P == 0)break;
		xsum = 0; M--;
		for(i = 0; i < N; i++){
			scanf("%d", &xi[i]);
			xsum += xi[i];
		}
		if(xi[M] == 0){
			result = 0;
		}else{
			result = 100*xsum*(100-P)/100/xi[M];
		}
		printf("%d\n", xi[M]?result:0);
	}
	return 0;
}