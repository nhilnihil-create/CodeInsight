#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int k;
    int a,b;
    cin>>k>>a>>b;
    if(b-a>=k)
        cout<<"OK";
    else{
        bool reshenie=false;
        for(int i=a;i<=b;i++){
            if(i%k==0)
            reshenie=true;
        }
    if(reshenie==true)
        cout<<"OK";
    else
        cout<<"NG";
    }
}
