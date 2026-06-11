#include<iostream>
#include<cmath>
using namespace std;

int main(){
    long long n,d;
    cin>>n>>d;
    long long x,y,cnt=0;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        double ans=sqrt(((double)(x*x)+(double)(y*y)));
        if(ans<=d) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}