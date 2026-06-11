#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
char s[105][105];
int a[105][105]={0};
int main()
{
    int h,w;
    cin >> h >> w;
    for(int i=1;i<=h;i++){
        cin >> s[i]+1;
    }
    for(int i=0;i<=h;i++)
        for(int j=0;j<=w;j++)
            a[i][j]=100005;
    if(s[1][1]=='#')
        a[1][1]=1;
    else
        a[1][1]=0;
    //a[0][0]=0;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(i==j&&i==1){
                continue;
            }
            if(s[i][j]=='.')
                a[i][j]=min(a[i-1][j],a[i][j-1]);
            else{
                if(s[i][j]!=s[i-1][j]){
                    a[i][j]=min(a[i-1][j]+1,a[i][j]);
                }
                else
                    a[i][j]=min(a[i-1][j],a[i][j]);
                if(s[i][j]!=s[i][j-1])
                    a[i][j]=min(a[i][j-1]+1,a[i][j]);
                else
                    a[i][j]=min(a[i][j-1],a[i][j]);
            }
        }
    }
//    for(int i=1;i<=h;i++)
//        for(int j=1;j<=w;j++)
//            cout << a[i][j] << " \n"[j==w];
    cout << a[h][w] <<endl;
    return 0;
}
