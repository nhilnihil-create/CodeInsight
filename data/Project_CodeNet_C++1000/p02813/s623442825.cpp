#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
int main()
{
  int a[10];//基础数组
int b[10];//存目标数组1
int c[10];//存目标数组2 
    int n,t2 = 0,t1 = 0;
    scanf("%d",&n);

   for(int i=0; i<n; i++){
    
        a[i] = i+1;
		
} //以0开头的存的是 这个最基本的哪一个数字 

        for(int i=0; i<n; ++i)
            scanf("%d",&b[i]);//每一个i表示一位数字
		 for(int i=0; i<n; ++i)
            scanf("%d",&c[i]);//每一个i表示一位数字
		

    do{
        t1++;
        int flag = 0;
        for(int i=0; i<n; ++i){
            if(a[i]!=b[i]){ //对比基本数字和存储的
			//如果不相等就是1 
			//退出循环开始演算基础的 继续拍
			//直到找到相等的 也就是位置 记录位置是第t个 
                flag = 1;
                break;
            }
        }
        if(!flag)
            break;
    }while(next_permutation(a,a+n));

    for(int i=0; i<n; i++){
     a[i] = i+1;
} 
    do{
        t2++;
        int flag = 0;
        for(int i=0; i<n; ++i){
            if(a[i]!=c[i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            break;
        }
    }while(next_permutation(a,a+n));

    printf("%d",abs(t1-t2));
    return 0;
}
