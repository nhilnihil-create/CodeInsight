#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v,p(n,0),q(n,0);
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    int a,b,i=0;
    bool flag=true;
    for(int i=1;i<=n;i++){
        v.push_back(i);
    }
    do{
        i++;
        if(v==p){
            a=i;
        }
        if(v==q){
            b=i;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<abs(a-b)<<"\n";
    return(0);
}