#include<stdio.h>
#include<queue>
using namespace std;
int mt,my,mn,X,Y,T;
int field[9][1010][1010] = {0};
int dx[] = {-1,0,1,0},dy[] = {0,-1,0,1};
int mouse(int i,int x,int y,int time)
{//printf("%d %d %d\n",x,y,time);
    queue<int> QX,QY,QT;
    QX.push(x);QY.push(y);QT.push(time);
    field[i][x][y] = i + 2;
    while(QX.size())
    {
        /*for(int l = 0; l < 10; l++)
        {
            for(int j = 0; j < 10; j++)
            {
                printf("%3d",field[i][j][l]);
            }
            printf("\n");
        }printf("\n");*/
        for(int j = 0; j < 4; j++)
        {
            if(0 > QX.front() + dx[j] || QX.front() + dx[j] >= my || 0 > QY.front() + dy[j] || QY.front() + dy[j] >= mt);
            else if(field[i][QX.front() + dx[j]][QY.front() + dy[j]] == i + 1)
            {
                X = QX.front() + dx[j];Y = QY.front() + dy[j];T = QT.front() + 1;
                return 0;
            }
            else if(field[i][QX.front() + dx[j]][QY.front() + dy[j]] == 0)
            {
                QX.push(QX.front() + dx[j]);QY.push(QY.front() + dy[j]);QT.push(QT.front() + 1);
                field[i][QX.front() + dx[j]][QY.front() + dy[j]] = i + 2;
            }
        }
        QX.pop();QY.pop();QT.pop();
    }
}
int main()
{
    char cha;
    scanf("%d%d%d",&mt,&my,&mn);
    scanf("%c",&cha);
    for(int i = 0; i < mt; i++)
    {
        for(int j = 0; j < my + 1; j++)
        {
            scanf("%c",&cha);
            if(cha == 'S')
            {
                X = j;Y = i;T = 0;
            }
            else if(cha == 'X')
            {
                for(int k = 0; k < 9; k++)
                {
                    field[k][j][i] = -1;
                }
            }
            else if('0' <= cha && cha <= '9')
            {
                field[cha - '0' - 1][j][i] = cha - '0';
            }
        }
    }//ok
    /*for(int k = 0; k < 9; k++)
    {
        for(int i = 0; i < t; i++)
        {
            for(int j = 0; j < y; j++)
            {
                printf("%3d",field[k][j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }*/
    for(int i = 0; i < mn; i++)
    {
        mouse(i,X,Y,T);
    }
    printf("%d\n",T);
    return 0;
}