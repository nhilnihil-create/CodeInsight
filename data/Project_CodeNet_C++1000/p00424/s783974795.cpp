
int main(void){
  int i,n;
  char list[128],x[2],before[2],after[2];

  while(1){
    scanf("%d",&n);
    if(!n) break;

    for(i=0;i<128;i++){
      list[i] = i;
    }
    while(n--){
      scanf("%s%s",before,after);
      list[before[0]] = after[0];
    }

    scanf("%d",&n);
    while(n--){
      scanf("%s",x);
      putchar(list[x[0]]);
    }
    putchar('\n');
  }

  return 0;
}