#include<bits/stdc++.h>
using namespace std;   
int main(){
    long long a,b,k;
    cin>>a>>b>>k;
    cout<<max(a-k,(long long)0)<<" "<<max(min(b,b+a-k),(long long)0)<<endl;
    return 0;
}