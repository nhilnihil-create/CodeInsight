#include<iostream>
#include<algorithm>
#include<cmath>
//#include<string>
//#include<set>
//#include<vector>
//#include<iomanip>
using namespace std;
int main(){

    int n;
    cin>>n;
    int x,m=0,k=0,in;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x>=m){k=m;m=x;in=i;}
        else if(x>=k){k=x;}
    }
    for(int i=0;i<n;i++){
        if(i==in){cout<<k;}
        if(i!=in){cout<<m;}
        if(i!=n-1){cout<<endl;}
    }
    return 0;
}
