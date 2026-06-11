#include<iostream>
#include<algorithm>
using namespace std;

const int MAX = 10005;

int row, col;
int cnt;

void disp(bool map[][MAX])
{
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
            cout<<map[i][j];
        cout<<endl;
    }
    cout<<endl;
}

int calu(bool map[][MAX])
{
    //disp(map);
    int sum=0;
    int tmp;
    for(int i=0; i<col; ++i)
    {
        tmp=0;
        for(int j=0; j<row; ++j)
            tmp+=map[j][i];
        tmp = tmp > row-tmp ? tmp : row-tmp;
        sum += tmp;
    }
    cnt = cnt > sum ? cnt : sum;
}

void dfs(bool map[][MAX], int num)
{
    if(num == row) return ;
    bool tmp[12][MAX];
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            tmp[i][j] = map[i][j];

    calu(tmp);
    dfs(tmp, num+1);

    for(int i=0; i<col; ++i)
        tmp[num][i] = !tmp[num][i];

    calu(tmp);
    dfs(tmp, num+1);
}

int main()
{
    bool map[12][MAX];
    while(cin>>row>>col && row)
    {
        for(int i=0; i<row; ++i)
            for(int j=0; j<col; ++j)
                cin>>map[i][j];
        //cnt = sum();
        cnt = 0;
        dfs(map,0);
        cout<<cnt<<endl;
    }
    return 0;
}