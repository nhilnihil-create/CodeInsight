#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    long a, b;
    cin>>a >>b;
    int count=1;
    while(b*count%a!=0){
        count++;
    }
    cout<<b*count<<endl;
}