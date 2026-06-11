#include <bits/stdc++.h>
using namespace std;
bool T=false;

int main(){
    string U,S,T;int A,B;
    cin>>S>>T>>A>>B>>U;
    if(S==U)cout<<A-1<<" "<<B;
    else cout<<A<<" "<<B-1;
}