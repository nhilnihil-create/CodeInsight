#include<iostream>
#include<map>
using namespace std;
int N,X,Y,M;
int main(){
    cin>>N;
    int x[N],y[N];
    for(int i=0;i<N;i++)cin>>x[i]>>y[i];
    map<pair<int,int>,int>m;
    for(int i=0;i<N-1;i++)for(int j=i+1;j<N;j++){
        X=x[i]-x[j],Y=y[i]-y[j];
        if(Y==0)X=abs(X);
        if(Y<0)X=-X,Y=-Y;
        M=max(M,++m[make_pair(X,Y)]);
    }
    cout<<N-M<<endl;
    return 0;
}