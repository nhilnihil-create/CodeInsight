#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N;
    cin>>N;
    int lis[100000];
    for(int i=0;i<N;i++)cin>>lis[i];
    for(int i=N-1;1<=i;i--){
        if(lis[i-1]>lis[i]){
            lis[i-1]--;
            if(lis[i-1]>lis[i]){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}