#include <bits/stdc++.h>
using namespace std;
int main(void){
    int i,j,c=1,p=0,a,b,y=0,x;
    cin >> a >> b;
    string g,f;
    for(i=0;i<b;i++)
    {
        p+=a*c;
        c=c*10;
    }
    c=1;
    for(i=0;i<a;i++)
    {
        y+=b*c;
        c*=10;
    }
    g=to_string(p);
    f=to_string(y);
    if(g<f)
    {
        cout << g << endl;
    }
    else
    {
        cout << f << endl; 
    }    
}
