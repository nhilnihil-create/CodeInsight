#include <bits/stdc++.h>

using namespace std;

int main()
{
    char S[3][7]={"Sunny","Cloudy","Rainy"};
    string input;
    cin>>input;
    if(input=="Sunny")
        cout<<S[1]<<endl;
    else if (input=="Cloudy")
        cout<<S[2];
   else
    cout<<S[0];
    return 0;
}
