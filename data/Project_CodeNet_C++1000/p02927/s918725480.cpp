#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int i,j,n,m,minn,maxx,tmp,q,t;
const int N=2e5+5;
int a[N];
int f[N];
int d[N];

int main(){
    ios::sync_with_stdio(false);
    int m,d;
    cin>>m>>d;
    int cnt=0;
    for(int i=22;i<=d;i++){
        int s=i%10;
        if(s<2)continue;
        int t=i/10;
        if(s*t<=m&&s*t>=1){
               // cout<<i<<endl;
                cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
