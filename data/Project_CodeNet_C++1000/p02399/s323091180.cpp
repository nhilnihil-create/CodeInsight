#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int a,b;
    cin>>a>>b;
    printf("%d %d %lf",a/b,a%b,(double)a/(double)b);
    cout<<endl;
    return 0;
}