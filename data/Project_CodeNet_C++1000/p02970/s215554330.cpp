#include <bits/stdc++.h>
using namespace std;
int main(){
    int N,K;
    cin>>N>>K;
    int x=K*2+1;
    int count=0;
    for(int i=0;i<7;i++){
        while(N>0){
            N-=x;
            count++;
        }
    }
    cout<<count<<endl;
}
