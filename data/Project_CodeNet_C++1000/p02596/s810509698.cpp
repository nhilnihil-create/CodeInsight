#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
    int K;
    cin >> K;
    bool flag=false;
    long long seven=7;
    int num=0;
    if(K%2==0 || K%5==0){
        flag=true;
    }
    while(flag==false){
        num++;
        if(seven%K==0){
            flag=true;
        }
        seven=(seven*10+7)%K;
    }
    if(num==0){
        cout << -1 << endl;
    } else {
        cout << num << endl;
    }
}