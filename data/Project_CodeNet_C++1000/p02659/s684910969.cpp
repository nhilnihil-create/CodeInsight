#include<bits/stdc++.h>

using namespace std;

int main(){
    long long int a;
    double b;
    long long int seki;
    cin>>a>>b;

    long long int c=((b+0.001)*100);
    seki=(a*c)/100;

    cout<<(long long int)(seki)<<endl;

}