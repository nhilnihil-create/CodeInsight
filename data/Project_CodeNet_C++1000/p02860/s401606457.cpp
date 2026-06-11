//IN THE NAME OF 'ALLAH'//
#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n ;
    cin>> n ;
    string s ;
    cin>> s ;
    int len = s.size();
    if(  s.substr( 0 , len/2) == s.substr( len/2 , len ) )cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
