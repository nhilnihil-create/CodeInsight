
int main(void){
  int n,a,b;
  int score[2];

  while(1){
    scanf("%d",&n);
    if(!n) break;
    score[0]=score[1]=0;
    while(n--){
      scanf("%d%d",&a,&b);
      if(a<b){
        score[1] += a+b;
      }
      else if(a>b){
        score[0] += a+b;
      }
      else{
        score[0] += a;
        score[1] += b;
      }
    }
    printf("%d %d\n",score[0],score[1]);
  }

  return 0;
}