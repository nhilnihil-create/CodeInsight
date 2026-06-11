#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


int main(){
    int n;
    scanf("%d",&n);
    set<string> s;
    for(int i=0;i<n;i++){
        char l[6],r[12];
        scanf("%s %s",&l,&r);
        string k=r,h=l;
        if(h=="insert"){
            s.insert(k);
        }else{
            if(s.find(k)!=s.end()){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}