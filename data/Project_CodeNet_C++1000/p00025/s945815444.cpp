#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool use[10];
int main()
{
    int a[4],b[4];
    while(~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])){
        memset(use,0,sizeof(use));
        for(int i=0;i<4;i++) use[a[i]]=1;
        scanf("%d%d%d%d",&b[0],&b[1],&b[2],&b[3]);
        int aa=0,bb=0;
        for(int i=0;i<4;i++){
            if(a[i]==b[i]) aa++;
            else if(use[b[i]]) bb++;
        }
        cout<<aa<<" "<<bb<<endl;
    }
    return 0;
}