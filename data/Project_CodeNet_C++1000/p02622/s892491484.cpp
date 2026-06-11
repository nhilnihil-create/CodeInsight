#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s , t;
    cin>>s>>t;
    int counto=0;
    int i ;
    for(i=0; i<s.size();i++){
        if(s[i]!= t[i]){counto+=1;}

    }
    cout<<counto;


    return 0;
}
