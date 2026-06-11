#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int w,h,x,y;
    cin>>w>>h>>x>>y;
    printf("%lf",double(w)*double(h)/2);
    cout<<" ";
    if (x+x==w&&y+y==h) {
        cout<<1<<endl;
    } else {
        cout<<0<<endl;
    }
}