#include<bits/stdc++.h>
using namespace std;
int x;

int main()
{
    cin>>x;
    while(1){
        bool xb=true;
        for (int i=2;i<sqrt(x);++i){
            if(x%i==0){
                xb=false;
                break;
            }
        }
        if (xb){
            break;
        }
        ++x;
    }
    cout<<x<<endl;
}