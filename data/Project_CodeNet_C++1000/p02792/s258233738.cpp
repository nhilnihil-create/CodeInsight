#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c[10][10],e,f,g,h,t=0;
    cin>>n;
    string s;
    char a,b;
    for(int i=1;i<=9;++i)
    {
        for(int j=1;j<=9;++j)
            c[i][j]=0;
    }
    for(int i=1;i<=n;++i)
    {
        string s=to_string(i);
            int l=s.size();
            if(s[l-1]!='0'){
                int x=s[0]-'0';
                int y=s[l-1]-'0';

                c[x][y]++;
            }
    }
    for(int i=1;i<=9;++i)
    {
        for(int j=1;j<=9;++j)
            t=t+c[i][j]*c[j][i];
    }
    cout<<t<<endl;
    return 0;
}
