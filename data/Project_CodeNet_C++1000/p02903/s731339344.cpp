#include <bits/stdc++.h>
typedef long long int ll; 
using namespace std;

int main() {
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int mat[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if((i<b)^(j<a))
            {
                mat[i][j]=1;
            }
            else
            {
                mat[i][j]=0;
            }
        }
    }
        for(int i=0;i<n;i++)
        {
        for(int j=0;j<m;j++)
        {
            cout<<mat[i][j];
        }
        cout<<"\n";
    }
    return 0;
}