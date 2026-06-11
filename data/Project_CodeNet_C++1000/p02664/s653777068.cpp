#include<cstdio>
#include<algorithm>
using namespace std;
char p[201000];
int main(){
    scanf("%s",p);
    for(int i=0;p[i];i++){
        if(p[i]=='?')p[i]='D';
    }
    printf("%s\n",p);
}
