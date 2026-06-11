#include<iostream>
#include<cmath>

using namespace std;

int main(){
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    int n=ceil(a/d);
    int m=ceil(c/b);
    if(n<m)
        cout<<"No\n";
    else
        cout<<"Yes\n";
}
