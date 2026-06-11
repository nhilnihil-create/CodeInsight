#include <bits/stdc++.h>
using namespace std;
long long  n,s;

int main(){
 cin>>n;
 for(int i=1;i<=n;i++){
    if(i%3!=0&&i%5!=0)s+=i;
 }
 cout<<s;
    return 0;}


