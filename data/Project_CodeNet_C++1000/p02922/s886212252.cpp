#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    int count;
    cin>>a>>b;
    if(b==1)
    cout<<"0"<<endl;
    else if(a>=b)
    cout<<"1"<<endl;
    else if(a<b)
    {   count=1;
    if((b-a)%(a-1)>0)
    count++;
        count+=(b-a)/(a-1);
        cout<<count<<endl;
    }
    

}