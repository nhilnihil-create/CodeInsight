#include<bits/stdc++.h>
using namespace std;

int main(){

    int h,a;
    int cnt=0;
    cin>>h;
    cin>>a;

    int x = h/a;
    while(h>0){
        h = h-a;
        cnt++;
    }
     cout<<cnt;

    return 0;


}
