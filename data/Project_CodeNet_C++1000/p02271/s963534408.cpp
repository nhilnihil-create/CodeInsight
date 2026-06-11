#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


int main(){
    int n,q;
    scanf("%d",&n);
    vector<int> a(n);
    for(auto&e:a){
        scanf("%d",&e);
    }
    scanf("%d",&q);
    vector<int> m(q);
    for(auto&e:m){
        scanf("%d",&e);
    }
    set<int> lst;
    for(int all=0;all< (1<<n);all++){
        int chk=0;
        for(int i=0;i<n;i++){
            if(all>>i & 1){
                chk+=a[i];
            }
        }
        lst.insert(chk);
    }
    for(int i=0;i<q;i++){
        if(lst.find(m[i])!=lst.end()){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
    return 0;
}