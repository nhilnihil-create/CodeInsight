#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,c,d;
    cin>>a;
    b=a/(60*60);
    c=a%(60*60)/60;
    d=a-b*(60*60)-c*60;
    cout<<b<<":"<<c<<":"<<d<<endl;// Your code here!
    
}

