#include<bits/stdc++.h>
using namespace std;
int x;
int main(){
    scanf("%d",&x);
    for(int i=1,j=x;;i++){
        if(!j){printf("%d\n",i);break;}
        j+=x;j%=360;
    }
    return 0;
}