#include <bits/stdc++.h>
using namespace std;

int main ()
{
string S,T;
string A="CSR";
int tot=0;
cin>>S>>T;
if(S.length()==3&&T.length()==3){
    for(int i=0;i<3;i++){
        if(S[i]==T[i]&&(S[i]==A[0]||S[i]==A[1]||S[i]==A[2])&&(T[i]==A[0]||T[i]==A[1]||T[i]==A[2])){
            tot++;
        }
    }
    cout<<tot;   
}

return 0;
}