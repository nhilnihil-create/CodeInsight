#include<bits/stdc++.h>
using namespace std;
typedef long long int INT;

INT pow(int n,int k)
{
    INT a=1;
    for (int i=1;i<=k;i++){
        a*=n;
    }
    return a;
}

int main()
{
    INT n;
    int k;
    cin>>n>>k;
    int i=0;
    while(1){
        if(n<pow(k,i)){
            cout<<i<<endl;
            break;
        }
        ++i;
    }
}