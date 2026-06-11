#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
    int N;
    cin>>N;
    int odd=0;
    
    rep(i,N){
        int cnt=0;
        int A=i+1;
        while(A!=0){
            cnt++;
            A/=10;
        }
        if(cnt%2==1){
            odd++;
        }
    }
    cout<<odd<<endl;
}
