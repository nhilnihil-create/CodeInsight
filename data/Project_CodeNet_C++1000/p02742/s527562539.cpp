#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase=1;
    //cin>>testcase;
    for(int p=0;p<testcase;p++){
    ll h=0,w=0;
    cin>>h>>w;
    if(h==1 ||  w==1)
        cout<<"1";
    else if(h*w%2==0)
        cout<<h*w/2;
    else
        cout<<(h*w)/2+1;



    }

    return 0;
}
