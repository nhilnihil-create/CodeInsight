#include <bits/stdc++.h>
using namespace std;

int addtax(int n,int p){
    return n*(100+p)/100;
}

int remtax(int n,int p){
    int ans = n*100/(100+p);
    if(addtax(ans,p)!=n)ans++;
    return (addtax(ans,p)==n ? ans : 0);
}

int main(void)
{
    int x,y,a,b,s;
    int max_sy;

    while(1){
        cin>>x>>y>>s;
        if(x==0 && y==0 && s==0)break;
        for(a=max_sy=1;;++a){
            b = remtax(s-addtax(a,x),x);
            if(!b)continue;
            if(a>b)break;
            max_sy = max(max_sy , addtax(a,y)+addtax(b,y));
        }
        cout<<max_sy<<endl;
    }

    return 0;
}