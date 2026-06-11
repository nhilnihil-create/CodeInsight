#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test=1;
    //cin>>test;
    while(test--){
        int n;
        cin>>n;
        int t=n%1000;
        if(t==0) cout<<0;
        else cout<<1000-t;
    }

    return 0;
}
