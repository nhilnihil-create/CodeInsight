#include<iostream>
#include<string>

using namespace std;

int main() 
{
    string S;
    cin>>S;

    if(S=="Sunny")
    {
        S="Cloudy";
    }
    else if(S=="Cloudy")
    {
        S="Rainy";
    }
    else
    {
        S="Sunny";
    }
    
    cout<<S<<endl;
    return 0;
}