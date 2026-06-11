#include<bits/stdc++.h>
using namespace std;
int main(void){
    int K;
    long long t;
    cin>>K;
    t = 7;
    for(long i=0;i<K;i++){
        if(t%K==0){

            cout<<i+1<<endl;
            return 0;
        }
        t = (t*10+7)%K;
    }
    cout<<-1<<endl;
    return 0;

}