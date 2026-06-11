#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,l;
    int s=0;
    int t=0;
    cin>>n>>l;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        a.at(i)=l+i;
    }
    if(a.at(0)>=0){
        t=a.at(0);
    }else if(a.at(0)<0&&abs(a.at(0))>=n){
        t=a.at(n-1);
    }
    for(int i=0;i<n;i++){
        s+=a.at(i);
        
    }
    s-=t;
    cout<<s<<endl;
}
 