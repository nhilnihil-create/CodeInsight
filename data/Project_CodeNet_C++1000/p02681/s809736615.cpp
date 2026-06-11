#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string S,T;
    getline(cin,S);
    getline(cin,T);

     if(S.substr(0,S.length())==(T.substr(0,(T.length()-1))))
   {
       cout << "Yes";
   }
   else
       cout<<"No";
    return 0;
}
