#include<iostream>

using namespace std;

int main()
{
    int i,j,l;
    bool flag=1;
    string s;
    cin >>l;
    cin >>s;
    if(l%2){ cout << "No"; return 0;}
    for(i=0,j=l/2;j<l;i++, j++) if(s[i]!=s[j]){ flag=0; break;}
    if(flag) cout << "Yes";
    else cout << "No";
}
