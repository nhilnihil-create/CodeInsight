#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>m;
    int remainderr=m%10;
    if(remainderr==2 || remainderr==4 || remainderr==5 || remainderr==7 || remainderr==9)
        cout<<"hon";
    else if(remainderr==0  || remainderr==1 || remainderr==6 || remainderr==8)
        cout<<"pon";
    else
        cout<<"bon";
}
