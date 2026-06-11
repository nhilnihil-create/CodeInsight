#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int a,b;
    cin>>a>>b;
    int B;
    B=b*10;
    int cnt=10;
    while(cnt>0){
        //cout<<B<<endl;
        if(B*8/100==a) {
            cout<<B<<endl;
            return 0;
        }
        B++;
        cnt--;
    }
    cout<<-1<<endl;
}