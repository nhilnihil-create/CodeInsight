#include<iostream>
#include<cstdio>
using namespace std;
using ll = long long;

int main(){
    ll w,h,x,y;
    cin>>w>>h>>x>>y;
    printf("%.10f %d\n",w*h/2.0,(x==w/2.0&&y==h/2.0)?1:0);
}