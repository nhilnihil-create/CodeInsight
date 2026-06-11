#include<iostream>
#include<cstdio>
using namespace std;
const int maxn =1010;
int mp[maxn][maxn];
int col[maxn];
int row[maxn];
int te[maxn][maxn];
int main(){

    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    for(int i = 1;i<=b; ++i){
        for(int j = 1;j<=m;++j){
            te[i][j] = 1;
        }
    }
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=a;++j){
            te[i][j]^=1;
        }
    }
    for(int i =1;i<=n;++i){
        for(int j = 1;j<=m;++j){
            printf("%d",te[i][j]);
        }
        printf("\n");
    }
    /*
    for(int i = 0;i<n;++i)row[i] = a,col[i] = b;
    if(n==1){
        if(b!=0){
            cout<<-1<<endl;
            return 0;
        }
        for(int i = 0;i<n;++i){
            if(a){
                a--;
                cout<<1;
            }
            else cout<<0;
        }
        cout<<endl;
        return 0;
    }

    for(int i = 0;i<n;++i){

        for(int j = 0;j<m;++j){
            if(col[j]&&row[i]){
                col[j]--;
                row[i]--;
                te[i][j]=1;
            }
            else{
                te[i][j] = 0;
            }
        }

    }
    int flag = 0;
    for(int i = 0;i<n;++i){
        if(row[i])flag = 1;
    }
    for(int i = 0;i<m;++i){
        if(col[i])flag = 1;
    }
    if(flag)cout<<-1<<endl;
    else{
        for(int i = 0;i<n;++i){
            for(int j = 0;j<m;++j){
                printf("%d",te[i][j]);
            }
            printf("\n");
        }
    }

    */

}
