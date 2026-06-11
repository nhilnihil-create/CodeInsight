#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int l[1000000],i,j,k,c=0,p=0;
    string s;
    cin >> s;
    c=s.size();
    for(i=0;i<c;i++)
    {
        p+=s.at(i)-'0';
    }
    if(p%9==0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;

}
