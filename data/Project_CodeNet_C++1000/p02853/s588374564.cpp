#include <bits/stdc++.h>
using namespace std;
int kq,x,y;
int main(){
    //freopen("dd.inp","r",stdin);
    //freopen("dd.out","w",stdout);
    cin>>x>>y;
    if (x==1)
        kq+=300000;
    else
    if (x==2)
        kq+=200000;
    else
    if (x==3)
        kq+=100000;


    if (y==1)
        kq+=300000;
    else
    if (y==2)
        kq+=200000;
    else
    if (y==3)
        kq+=100000;
    if (x==1&&y==1)
        kq+=400000;
    cout<<kq;
}
