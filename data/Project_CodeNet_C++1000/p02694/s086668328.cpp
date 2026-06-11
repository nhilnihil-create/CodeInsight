#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X;
    cin>>X;
    int count = 0;
    long long now=100;
    
    while(now<X){
        count++;
        now = now + (now/100);
    }
    
    cout<<count<<endl;
}


