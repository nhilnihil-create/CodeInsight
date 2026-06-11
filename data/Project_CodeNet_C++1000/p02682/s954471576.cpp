#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long int a,b,c,k;
    cin>>a>>b>>c>>k;
    long long int result=0;
    if(k<=a)
        result=k*1;
    else if(k<=(a+b))
        result=a*1;
    else{
        int temp=k;
        temp=temp-(a+b);
        //cout<<temp;
        result=(a-temp)*1;
    }
    cout<<result;
}
