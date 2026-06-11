#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>

using namespace std;

string s;

int main()
{

    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>> s;
    int sum=0;
    for(int i=0;i<s.length();i++)   {
        sum += s[i]-48;
    }
    if(!(sum%9)){ cout<< "Yes" << endl; }
    else{ cout<< "No" << endl; }

    return 0;
}
