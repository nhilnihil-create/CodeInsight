#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


int main(){
    double pai=3.141592653589;
    int n,ans=0,chk,tmp;
    scanf("%d",&n);
    list<int> lst;
    for(int i=0;i<n;i++){
        char c[12];
        int p;
        scanf("%s %d",&c,&p);
        string s=c;
        if(s=="deleteFirst"){
            lst.pop_front();
        }else if(s=="deleteLast"){
            lst.pop_back();
        }else if(s=="insert"){
            lst.push_front(p);
        }else{
            for(auto itr=lst.begin(); itr!=lst.end();itr++){
                if(*itr==p){
                    lst.erase(itr);
                    break;
                }
            }
        }
    }
    int l=lst.size();
    for(int i=0;i<l-1;i++){
        printf("%d ",*lst.begin());
        lst.pop_front();
    }
    printf("%d\n",*lst.begin());
    return 0;
}