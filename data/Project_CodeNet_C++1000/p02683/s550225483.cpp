#include <iostream>
#include <stdio.h>

using namespace std;

int N,M,X,tol_book,cost,ans=1e9;
int score[15][15],money[15];//col列
int book_cho[15],sum_col[15];//choic_book = tar_row

void Dfs(int num_book)
{
    int i,j;
    if(num_book==tol_book+1)//选够书了
    {
        for(i=1;i<=M;++i)
            sum_col[i]=0;

        for(i=1;i<=tol_book;++i)//选多少书
            for(j=1;j<=M;++j)//计算所有列
                sum_col[j]+=score[ book_cho[i] ][j];

        for(i=1;i<=M;++i)
            if(sum_col[i]<X)
                return;//分不够

        cost=0;
        for(i=1;i<=num_book;++i)
            cost+=money[ book_cho[i] ];

        if(ans>cost)
            ans=cost;
    }
    else
    {
        for(i=book_cho[num_book-1]+1;i<=N;++i)//每次从下一本书开始
        {
            book_cho[num_book]=i;
            Dfs(num_book+1);
        }
    }
    return;
}

int main()
{
    int i,j;

    scanf("%d%d%d",&N,&M,&X);
    for(i=1;i<=N;++i)
    {
        scanf("%d",&money[i]);
        for(j=1;j<=M;++j)
            scanf("%d",&score[i][j]);
    }

    for(tol_book=1;tol_book<=N;++tol_book)//选择书的数量
    {
        book_cho[0]=0;//没有已选书，书号为0
        Dfs(1);
    }

    if(ans==1e9)
        printf("-1\n");
    else
        printf("%d\n",ans);

    return 0;
}