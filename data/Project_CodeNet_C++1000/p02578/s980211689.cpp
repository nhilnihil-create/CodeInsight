#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

typedef long long LL;
int n;

int main(){
    cin>>n;
    int t,last;
    LL sum=0;
    cin>>last;
    for(int i=1;i<n;++i){
        cin>>t;
        if(t<last){
            sum+=(last-t);
        }
        else last=t;
    }
    cout<<sum<<endl;
    return 0;
}