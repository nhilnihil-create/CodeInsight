#include<bits/stdc++.h>
using namespace std;
int main(){vector<string> s;
string p,x;
long long n,i;
cin>>n;
long long a[n],j,k=0;
for(i=0;i<n;i++){
    cin>>p;
    s.push_back(p);
    cin>>a[i];
}cin>>x;
for(i=0;i<n;i++){
    if(x==s[i]){
        j=i;break;
    }
}for(i=j+1;i<n;i++){
    k=k+a[i];
}cout<<k;

    return 0;
  
}
