#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    int sum=(x/500)*1000;
    x=x%500;
    sum+=(x/5)*5;
    cout<<sum<<endl;
}