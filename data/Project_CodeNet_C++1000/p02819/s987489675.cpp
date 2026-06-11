#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<string>
using namespace std;
int main(){
    long long int x,c=0;
    cin>>x;
    if(x==2)
    {
        cout<<x<<endl;

    }
    else{while(1){
    for (int i=2;i<=sqrt(x);i++)
    {
        if(x%i==0){c++;
        break;}
    }
    if(c==0)
    {
        cout<<x<<endl;
        break;
    }
    else{x++;
    c=0;
    }
}}
    return 0;

}

