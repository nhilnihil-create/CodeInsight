#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int latte=300000;
int main(){
    bool flag[latte];
    fill(flag,flag+latte,true);
    flag[0]=flag[1]=false;
    for(int i=2;i*i<latte;i++){
        if(flag[i]){
            for(int j=i*i;j<latte;j+=i)flag[j]=false;
        }
    }

    int n;
    while(cin>>n,n){
        int cnt=0;
        for(int i=n+1;i<=n*2;i++)
            if(flag[i])cnt++;

        cout<<cnt<<endl;
    }
    return 0;
}