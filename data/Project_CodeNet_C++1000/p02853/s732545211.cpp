#include<bits/stdc++.h>
using namespace std;
long long sum=0;
void cnt(long long a){
    if(a==1)
        sum +=300000;
    else if(a==2)
        sum +=200000;
    else if(a==3)
        sum +=100000;
    else
    {
        /* code */
    }
    
}
int main(){
    int x,y;
    cin>>x>>y;
    cnt(x);
    cnt(y);
    if(x==1 && y==1)
        sum +=400000;
    cout<<sum;
    return 0;
}