#include<cstdio>
#include<algorithm>
using namespace std;
bool field[15][10005];
int r, c;
int maxium = 0;
int sumup()
{
    //按照列来统计，只取统计一列中正面或背面朝上更多的，相当于把这一列反面
    int sum = 0, cnt;
    for(int j = 0; j < c; j++){
        cnt = 0;
        for(int i = 0; i < r; i++){
            cnt += field[i][j];
        }
        sum += max(cnt, r - cnt);
    }
    return sum;
}
void rev(int n)
{
    for(int j = 0; j < c; j++){
        field[n][j] = !field[n][j];
    }
}
int dfs(int n)
{
    if(n == r)
        return maxium = max(maxium, sumup());
    rev(n);
    dfs(n + 1);
    rev(n);
    dfs(n + 1);
}
int main()
{
    while(scanf("%d%d", &r, &c) == 2 && r){
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf("%d", &field[i][j]);
            }
        }
        int res = dfs(0);
        printf("%d\n", res);
    }
    return 0;
}

