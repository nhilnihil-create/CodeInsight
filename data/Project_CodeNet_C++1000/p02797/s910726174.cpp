#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main(){
    int n,m,s;
    scanf("%d%d%d",&n,&m,&s);
    if (m == n){
        for (int i=0;i<n-1;i++) printf("%d ",s);
        printf("%d\n",s);
    }
    else{
        int temp;
        if (s == 1000000000) temp = 999999999;
        else temp = s+1;
        for (int i=0;i<m;i++) printf("%d ",s);
        for (int i=m;i<n-1;i++) printf("%d ",temp);
        printf("%d\n",temp);
    }
}