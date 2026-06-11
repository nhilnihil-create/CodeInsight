#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>

using namespace std;
int main()
{
  
    int n,t2 = 0,t1 = 0;
    scanf("%d",&n);
    int a[10][10];

    for(int i=0; i<n; ++i)
        a[0][i] = i+1;  //以0开头的存的是 这个最基本的哪一个数字 

    for(int j=1; j<=2;++j)
        for(int i=0; i<n; ++i)
            scanf("%d",&a[j][i]);//每一个i表示一位数字
			//两次存储 

    do{
        t1++;
        int flag = 0;
        for(int i=0; i<n; ++i){
            if(a[0][i]!=a[1][i]){ //对比基本数字和存储的
			//如果不相等就是1 
			//退出循环开始演算基础的 继续拍
			//直到找到相等的 也就是位置 记录位置是第t个 
                flag = 1;
                break;
            }
        }
        if(!flag)
            break;
    }while(next_permutation(a[0],a[0]+n));

    for(int i=0; i<n; ++i)
        a[0][i] = i+1;


    do{
        t2++;
        int flag = 0;
        for(int i=0; i<n; ++i){
            if(a[0][i]!=a[2][i]){
                flag = 1;
                break;
            }
        }
        if(!flag){
            break;
        }
    }while(next_permutation(a[0],a[0]+n));

    printf("%d",abs(t1-t2));
    return 0;
}
