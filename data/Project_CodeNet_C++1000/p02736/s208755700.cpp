#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int main(){
    int n;
    string s; 
    cin>>n>>s;
    int *a=new int[n];
    int x=0,ans=0;
    for (int i=0;i<n;++i){
        a[i]=s[i]-'1';
        x|=(a[i]==1);
    }
    for (int i=0;i<n;++i) if (((n-1)&i)==i) ans^=(x?a[i]%2:a[i]/2);
    cout << ans*(x?1:2) << '\n';
    delete a;
    return 0;
}