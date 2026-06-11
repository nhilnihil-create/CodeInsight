#include<bits/stdc++.h>
using namespace std;
int main(){long long q,i,p=0;
string n,m;
cin>>n>>m;
for(i=0;i<3;i++){
    if(n[i]==m[i])
    p++;
}cout<<p;
    return 0;
}
