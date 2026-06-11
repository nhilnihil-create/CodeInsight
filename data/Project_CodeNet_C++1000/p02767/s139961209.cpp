#include<iostream>
#include<math.h>
using namespace std;

#define rep(i,n) for(i=0;i<N;i++)

int main(){
    int N;
    cin >> N;
    int x[N];
    int i;
    rep(i,N){
        cin>>x[i];
    }
    int sum=0;
    rep(i,N){
        sum+=x[i];
    }
    double pos=(double)sum/N;
    int ans1=(int)pos;
    int ans2=(int)(pos+1);
    int min1=0,min2=0;
    rep(i,N){
        min1+=(x[i]-ans1)*(x[i]-ans1);
        min2+=(x[i]-ans2)*(x[i]-ans2);
    }
    if(min1<min2){
        cout<<min1;
    }else{
        cout<<min2;
    }
}
