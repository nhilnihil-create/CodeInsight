#include<bits/stdc++.h>

using namespace std;

int main(){
    long long a,b,c;    cin>>a>>b>>c;
    long long A = 4*a*b;
    long long B = (c-a-b);
    //cout<<A<<" "<<B<<"\n";
    if(A<B*B && B>0){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}
