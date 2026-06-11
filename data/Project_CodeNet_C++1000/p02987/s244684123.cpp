#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() {

    string s;
    cin>>s;
    int a[4];
    int n=sizeof(a)/sizeof(a[0]);
    a[0]=(int)s[0];
    a[1]=(int)s[1];        
    a[2]=(int)s[2];
    a[3]=(int)s[3];
    
    sort(a,a+n);
    if(a[0]==a[1] && a[2]==a[3] && a[1]!=a[2]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}
