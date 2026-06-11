#include <bits/stdc++.h>

using namespace std;


int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool t=false,w=false;
    for(int i=0; ; i++){
        if(c<=0){
            t=true;
            break;
        }
         if(a<=0){
            w=true;
            break;
        }
        if(i%2==0){
            c-=b;


        }
        else
            a-=d;
    }
    if(t==1)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
