#include<bits/stdc++.h>

using namespace std;

int main(){

string S;
int K;
    cin>>K;

fflush(stdin); cin>>S;

if(K>=S.length())
{
    cout<<S;
}
if(K<S.length())
{
    string k="";
    for(int i=0;i<K;i++)
        {
            k=k+S[i];
        }
        k=k+"...";
        cout<<k;
}
return 0;
}
