#include<bits/stdc++.h>
using namespace std;
int main(){
    long n,m,l;
    cin>>n>>m>>l;
    long a[n][m];
    long  b[m][l];
    for(long i=0;i<n;i++){
        for(long j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(long i=0;i<m;i++){
        for(long j=0;j<l;j++){
            cin>>b[i][j];
        }
    }
    long c[n][l];
    long h=0;
    for(long i=0;i<n;i++){
        for(long j=0;j<l;j++){
            h=0;
            for(long k=0;k<m;k++){
                h+=a[i][k]*b[k][j];
            }
            c[i][j]=h;
        }
    }
    for(long i=0;i<n;i++){
        for(long j=0;j<l;j++){
            if(j==0){
                cout<<c[i][j];
            }
            else{
                cout<<' '<<c[i][j];
            }
        }
        cout<<endl;
    }
}
