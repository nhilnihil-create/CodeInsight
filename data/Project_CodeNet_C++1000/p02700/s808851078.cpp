#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int taka=(a-1)/d+1;
    int aoki=(c-1)/b+1;
    if(taka>=aoki) {
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
