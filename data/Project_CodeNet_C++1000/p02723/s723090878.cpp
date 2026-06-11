#include<iostream>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int j,l;
    l = s.length();
    bool i = false;
    if( s[2]==s[3] )
        if( s[4]==s[5] ){
            cout<<"Yes"<<endl;
            i = true;
            }


    if(i==false)
        cout<<"No"<<endl;


}
