#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>>x;

    int q=x/100;
    int r=x%100;

    cout<<(r<=q*5 ? 1 : 0)<<endl;
}