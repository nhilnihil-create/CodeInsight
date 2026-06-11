#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, dif, i;

    cin>>n>>k;

    if(k==1){
        cout<<"0"<<endl;
    }
    else{
        dif = n -k;
        cout<<dif<<endl;
    }
}
