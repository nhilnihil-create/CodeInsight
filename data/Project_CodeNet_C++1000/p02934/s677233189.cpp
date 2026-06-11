#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
    int N;
    double ans=0;
    cin>>N;
    for(int i=0;i<N;i++){
        double a;
        cin>>a;
        ans+=1/a;
    }
    cout<<1/ans<<endl;
    return 0;
}
