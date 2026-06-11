#include <iostream>

using namespace std;
 string s; int a=1; int maX=0;
int main()
{
    cin >> s;
    for(int x=0; x<s.length();x+=1)
    if (s[x] == 'R')
    {
        if(s[x]==s[x-1])
            a=a+1;
        else 
            a=1;
        
        maX = max (maX,a);  
    }
    cout << maX;

}
