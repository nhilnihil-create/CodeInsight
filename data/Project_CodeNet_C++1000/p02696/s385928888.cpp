#include<bits/stdc++.h>
#define AlisherAnush KamilaLaylo

using namespace std;

long long a,b,c,q,d;

int main(){
    cin>>a>>b>>c;
    q=min(b-1,c);
    cout<<((a*q/b)-a*(q/b));
}
