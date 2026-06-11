#include<iostream>
using namespace std;
string S,s;
long long K,cnt;
int main(){
    cin>>S>>K;
    string s(S.size(),char(S[0]));
    if(S==s){cout<<(S.size()*K)/2LL<<endl;return 0;}
    for(int i=1;i<S.size();i++)if(S[i-1]==S[i])cnt++,i++;
    if(S[0]!=S.back()){cout<<cnt*K<<endl;return 0;}
    int a=0,b=0;
    while(S[a]==S[0])a++;
    while(S[S.size()-1-b]==S[S.size()-1])b++;
    cout<<cnt*K-(a/2+b/2-(a+b)/2)*(K-1)<<endl;
    return 0;
}