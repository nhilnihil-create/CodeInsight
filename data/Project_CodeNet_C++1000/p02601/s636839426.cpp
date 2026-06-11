#include<bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,o;
    cin>>a>>b>>c>>o;
    int bneed=0;
    int cneed=0;
    bool shouldno=false;
    while (a>=b)
    {
        if(o==0)
        {
            shouldno = true;
            break;
        }
        b = b*2;
        o--;
    }
    while (b>=c)
    {
        if(o==0)
        {
            shouldno = true;
            break;
        }
        c = c*2;
        o--;
    }
    if(shouldno)
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    
    

    //system("PAUSE");





}