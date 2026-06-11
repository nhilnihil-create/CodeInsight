#include <iostream>
#include <bits/stdc++.h>
#include <set>

using namespace std;
int n,S[1000000];
bool cmp(const int a,const int b){
    return a>b;
}


bool mcmp(int t){
    if(t==1) return true;
    int tt = t/2;
    for(int i=0;i<tt;++i){
        if(S[i]<=S[i+tt]) return false;
    }
    return mcmp(t/2);
}

int main()
{
    scanf("%d",&n);
    int t = 1;for(int i=0;i<n;++i)t*=2;
    multiset<int> ss;
    for(int i=0;i<t;++i){scanf("%d",S+i);ss.insert(S[i]);}
    sort(S,S+t,cmp);
    bool yes = true;
    vector<int> bg;bg.push_back(S[0]);
    ss.erase(ss.find(S[0]));
    while(!ss.empty()&&yes){
        for(int i=0,st=bg.size();i<st;++i){
            auto pos = ss.lower_bound(bg[i]);
            if(pos==ss.begin()){
                yes = false;break;
            }
            bg.push_back(*(--pos));
            ss.erase(pos);
        }
    }
    if(yes) printf("Yes\n");
    else printf("No\n");

    return 0;
}
