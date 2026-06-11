#include<iostream>
using namespace std;
string S;
int K;
int main(){
    cin>>S;
    K=S.size();
    for(int i=1;i<S.size();i++)if(S[i-1]==S[i])K--,i+=2;
    cout<<K<<endl;
    return 0;
}