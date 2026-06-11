#include<iostream>
using namespace std;
int main()
{
string s[4] = {"Sunny","Cloudy","Rainy","Sunny"};
string temp;
cin >> temp;
for ( int i=0;i<3;i++)
    if(temp == s[i])
        cout << s[i+1] << endl;
}
