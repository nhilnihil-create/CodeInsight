#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(){
    long long N,K,R,S,P;
    string T;
    cin>>N>>K;
    cin>>R>>S>>P;
    cin>>T;
    ll res=0;
    for(int i=0;i<N;i++)
    {
        if(T[i]=='r'){
            if(T[i+K]=='r')T[i+K]='x';
        }
        else if(T[i]=='s'){
            if(T[i+K]=='s')T[i+K]='x';
        }
        else if(T[i]=='p'){
            if(T[i+K]=='p')T[i+K]='x';
        }
    }
    for(int i=0;i<N;i++)
    {
        if(T[i]=='r')res+=P;
        else if(T[i]=='s')res+=R;
        else if(T[i]=='p')res+=S;
    }
    cout<<res;
}