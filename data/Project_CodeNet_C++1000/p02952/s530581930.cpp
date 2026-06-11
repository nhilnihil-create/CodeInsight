#include<bits/stdc++.h>
using namespace std;

int i,j,cnt,degit,N;

int main(){
    cin >> N;

    for(i=0,cnt=0;i<=N;++i){
        for(j=i,degit=0;j;){
            j/=10;
            ++degit;
        }
        if(degit%2){
            ++cnt;
        }
    }

    cout << cnt;

    return 0;
}
