#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N,X,T;
    cin>>N>>X>>T;
    int tmp = 0;
    tmp = N%X;
    int ttmp = N/X;
    int ans = 0;
    if(tmp==0){
        ans = ttmp * T;
    }
    else{
        ans = (ttmp+1)*T;
    }
    cout<<ans<<endl;
}