#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int h,w;cin>>h>>w;
    string s[h];
    for (int i=0;i<h;i++)
        cin>>s[i];
    int l[h][w]{},r[h][w]{},u[h][w]{},d[h][w]{};
    for (int i=0;i<h;i++)
        for (int j=1;j<w;j++)
            if (s[i][j-1]=='.'&&s[i][j]=='.')
                l[i][j]=l[i][j-1]+1;
    for (int i=0;i<h;i++)
        for (int j=w-2;j>=0;j--)
            if (s[i][j+1]=='.'&&s[i][j]=='.')
                r[i][j]=r[i][j+1]+1;
    for (int i=0;i<w;i++)
        for (int j=1;j<h;j++)
            if (s[j-1][i]=='.'&&s[j][i]=='.')
                u[j][i]=u[j-1][i]+1;
    for (int i=0;i<w;i++)
        for (int j=h-2;j>=0;j--)
            if (s[j+1][i]=='.'&&s[j][i]=='.')
                d[j][i]=d[j+1][i]+1;
    int mx=0;
    for (int i=0;i<h;i++)
        for (int j=0;j<w;j++)
            if (s[i][j]=='.')
                mx=max(mx,l[i][j]+r[i][j]+u[i][j]+d[i][j]+1);
    cout<<mx<<endl;
    return 0;
}