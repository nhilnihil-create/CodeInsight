#include <iostream>
#include <string>
using namespace std;
int main(){
    int count=0;
    string S,N;
    cin>>S>>N;
    for(unsigned int a=0;a<S.size();a++)
    {  if(S[a]!=N[a])
            count++;}
    cout<<count;
    return 0;
}