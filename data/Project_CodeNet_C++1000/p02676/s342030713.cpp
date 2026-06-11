#include <bits/stdc++.h>
#include <iostream> 
#include <stdio.h>
#define MAX 200005
typedef long long ll; 
using namespace std; 
int main () 
{

    int k; 
    cin >> k; 
    string s; 
    cin >> s;
    string ans;  

    string dots("...");

    if (k >= s.length())
    {
        cout << s << endl; 
    }
    else 
    {
        cout << s.substr(0,k) << "..." << endl; 
    }
     
    return 0; 
}
