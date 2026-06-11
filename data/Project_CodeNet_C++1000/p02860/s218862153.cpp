#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,c=1,x=0,v=0,i,p=0;
    string s;
    cin >> n >> s;
    if(n%2!=0)
    {
        cout << "No" << endl;
        return 0;
    }
    v=n/2;
    if(s.substr(0,v)==s.substr(v))
       {
           cout << "Yes" <<endl;
       }
    else
    {
        cout << "No" << endl;
    }

    return 0;

}
