#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    string s, p, ss;
 
    cin >> s >> p;
    ss = s + s;
    if (ss.find(p) != string::npos) cout << "Yes" << endl;
    else cout << "No" << endl;
}