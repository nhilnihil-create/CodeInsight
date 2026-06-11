#include <bits/stdc++.h>
using namespace std;

int main(){
    long long X;
    cin>>X;
    int count = 0;
    for(long long i=100;i<X;i=i+(i/100)){
        count ++;
    }
    cout<<count<<endl;
}
