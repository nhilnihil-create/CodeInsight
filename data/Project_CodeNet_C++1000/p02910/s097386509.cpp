#include <bits/stdc++.h>
using namespace std;
#include <math.h>
const int64_t INF=9999999999999999;
int main() {
 string S;
 cin>>S;
 for(int i=0;i<S.size();i++){
    if(i%2==0){if(S[i]=='L'){cout<<"No"<<endl;return 0;}}
    else{if(S[i]=='R'){cout<<"No"<<endl;return 0;}}
 }
 cout<<"Yes"<<endl;
 return 0;}