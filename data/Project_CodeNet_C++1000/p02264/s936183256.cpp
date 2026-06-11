#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct pro{
    int time;
    char name[10];
};
void output(pro* process){
    printf("%s %d\n",process->name,process->time);
}
pro ans[100000];
queue<pro> que;
int n,q,c=0,now=0;
int main(){
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++){
        pro process;
        scanf("%s %d",process.name,&process.time);
        que.push(process);
    }
    while(!que.empty()){
        pro process=que.front();
        que.pop();
        if(process.time<=q){
            now+=process.time;
            pro a;
            a.time=now;
            strcpy(a.name,process.name);
            ans[c]=a;
            c++;
        }else{
            process.time-=q;
            now+=q;
            que.push(process);
        } 
    }
    for(int i=0;i<n;i++){
        output(&ans[i]);
    }
    return 0;
}