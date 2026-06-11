#include <iostream>
#include<queue>
#include<cstdio>
using namespace std;
int main()
{
    int key;
    char s[1001];
    priority_queue<int>PQ;
    while(1){
            scanf("%s",s);
        if(s[0]=='i'){
            scanf("%d\n",&key);
            PQ.push(key);
        }else if(s[0]=='e'&&s[1]=='x'){
            printf("%d\n",PQ.top());
            PQ.pop();
        }else{
        break;
        }
    }
    return 0;
}