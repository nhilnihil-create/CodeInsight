#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int n,x;
    while(cin>>n>>x&&n!=0){int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)break;
            for(int k=1;k<=n;k++)
            {
                if(k==i)break;
                if(k==j)break;
                if(i+j+k==x)cnt++;
            }
        }
    }
        cout<<cnt<<endl;
    }}