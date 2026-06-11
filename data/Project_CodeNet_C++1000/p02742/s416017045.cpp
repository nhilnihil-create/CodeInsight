#include <stdio.h>

int main(void)
{
    long H,W;
    long ret;
    scanf("%ld %ld",&H,&W);
    // H or Wどちらかが1ならば答えは1
    if (( H == 1 )|| ( W == 1)){
        printf("1\n");
        return 0;
    }
    //積が偶数か奇数かで+1するか判定する
    if((H * W)%2 == 1){
        //奇数
        ret = H*W / 2 + 1;
    }else
    {
        ret = H*W/2;
    }
    printf("%ld\n",ret);
    return 0;
}