#include <iostream>
#include <queue>
using namespace std;
int ball[10];
int dfs(int k,int B,int C)
{
    if(k == 10)
        return 1;
    if(ball[k] > B)
        return dfs(k + 1,ball[k],C);
    if(ball[k] > C)
        return dfs(k + 1,B,ball[k]);
    return 0;
}
int main(void)
{
    int n;
    cin>>n;
    while(n--){
        int i;
        queue<int> left,right;
        for(i = 0;i < 10;i++)
            cin>>ball[i];
        if(dfs(0,0,0))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}