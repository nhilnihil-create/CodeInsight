#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int x;
    cin>>x;
    int a,b;
    int tmp,tmp2;
    bool flg=false;
    for(a=-118;a<=119;a++){
        for(b=-119;b<a;b++){
            tmp=pow(a,5)-pow(b,5);
            tmp2=pow(a,5)+pow(b,5);
            if(tmp==x){
                flg=true;
                break;
            }
            if(tmp2==x){
                flg=true;
                break;
            }
        }
        if(flg) break;
    }
    cout<<a<<" "<<b<<endl;
}