#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int q;
int len[1005][1005];

int common(string a,string b,int m,int n){
    int i,j;
    for(i=0;i<=m;i++)len[i][0]=0;
    for(i=0;i<=n;i++)len[0][i]=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(a[i]==b[j])len[i+1][j+1]=len[i][j]+1;
            else len[i+1][j+1]=max(len[i+1][j],len[i][j+1]);
        }
    }
    return len[m][n];
}

int main()
{
    cin>>q;
    int i;
    for(i=0;i<q;i++){
        string a,b;
        cin>>a>>b;
        int m=a.length();
        int n=b.length();
        cout<<common(a,b,m,n)<<endl;
    }
    return 0;
}