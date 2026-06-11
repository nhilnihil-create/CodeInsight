#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,i=0,j,c=0,p,h[1000010],m=0;
    string s;
    cin >> n >> s;
    c=s.size();
    for(i=0;i<c-2;i++)
    {
        if(s.substr(i,3)=="ABC")
        {
            m++;
        }
    }
    cout << m << endl;
    return 0;

}
