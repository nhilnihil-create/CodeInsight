#include <iostream>


using namespace std;

int main()
{
string S;
getline(cin,S);
if((S.length()==6)&&(S[2]==S[3])&&(S[4]==S[5]))
{
    cout<<"Yes";

}
else
{
    cout<<"No";
}
return 0;
}
