#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int num, org;
    cin>> num >> org;
    int cnt=0;
    for (int i=0; i<num; i++){
        long long int a, b;
        cin>>a >> b;
        cnt+= a*a + b*b <= org*org;
    }
    cout<<cnt;
}
