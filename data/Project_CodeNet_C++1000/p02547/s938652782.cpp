#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    bool zoro=false;
    int count=0;
    rep(i,n){
        int d1, d2;
        cin>>d1 >>d2;
        if(d1==d2 && zoro && count==2){
            cout<<"Yes"<<endl;
            return 0;
        }else if(d1==d2 && zoro){
            count++;
        }else if(d1==d2 && !(zoro)){
            zoro=true;
            count=1;
        }else if(d1!=d2){
            zoro=false;
            count=0;
        }
    }
    cout<<"No"<<endl;
}