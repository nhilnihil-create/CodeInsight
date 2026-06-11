#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
   string str; cin>>str; int l=str.length(),c=0,d=0;
   for(int i=0;i<l/2;i++){
     if(str[i]==str[l-i-1])c++;
   } if(c==l/2)d++; c=0;
   for(int i=0;i<l/4;i++){
     if(str[i]==str[l/2-i-1])c++;
   } if(c==l/4)d++; c=0;
   for(int i=0;i<l/4;i++){
     if(str[i+l/2+1]==str[l-i-1])c++;
   }if(c==l/4)d++; if(d==3)cout<<"Yes"; else cout<<"No"; cout<<endl;
}
