#include<bits/stdc++.h>
#define ll long long
#define pa pair<int,int>
using namespace std;
vector<pa>ans;
set<int>tr;
int n;
void output(){
    for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].first,ans[i].second);
}
int main(){
    ans.clear();
    scanf("%d",&n);
    int p=1;
    while(p<=n){
        if(n==p)return puts("No"),0;
        p<<=1;
    }
    puts("Yes");
    bool flag=0;
    if(n%2==0){
        flag=1;
    }
    for(int i=1;i<3;i++){
        ans.push_back(make_pair(i,i+1));
        ans.push_back(make_pair(i+n,i+1+n));
    }
    ans.push_back(make_pair(3,n+1));
    for(int i=4;i+1<=n;i+=2){
        ans.push_back(make_pair(1,i));
        ans.push_back(make_pair(i,i+1));
        ans.push_back(make_pair(1,i+1+n));
        ans.push_back(make_pair(i+n,i+1+n));
    }

    if(flag){
        tr.clear();
        for(int i=1;i<n;i++)tr.insert(i);
        for(int i=2;i<n;i++){
            if(tr.count(n^i^1)){
                int a=n^i^1,b=i;
                if(a==b)continue;
                if(a&1){
                    ans.push_back(make_pair(a+n,n));
                }
                else{
                    ans.push_back(make_pair(a,n));
                }
                if(b&1){
                    ans.push_back(make_pair(b+n,2*n));
                }
                else{
                    ans.push_back(make_pair(b,2*n));
                }
                output();
                return 0;
            }
        }
    }
    else{
        output();
    }
    return 0;
}
