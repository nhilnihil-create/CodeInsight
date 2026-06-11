#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s[100000],po,ne,W,a,A=100000,B=100000;
vector<ll>v1,v2;
int main(void){
    cin>>n;
    if(n==2){
        cin>>A>>B;
        cout<<abs(A-B)<<endl;
        if(A>B)cout<<A<<" "<<B<<endl;
        else cout<<B<<" "<<A<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a;
        if(a>=0){
            po+=a;
            if(A==100000)A=a;
            else v1.push_back(a);
        }
        else{
            ne-=a;
            if(B==100000)B=a;
            else v2.push_back(a);
        }
    }
    if(A!=100000&&B!=100000){
        cout<<po+ne<<endl;
    if(v1.size()==0){
        cout<<A<<" "<<B<<endl;
    }
    else cout<<B<<" "<<A<<endl;
    W=B-A;
    for(int i=0;i<v1.size();i++){
        if(i==v1.size()-1){cout<<v1[i]<<" "<<W<<endl;}
        else cout<<W<<" "<<v1[i]<<endl;
        W-=v1[i];
    }
    W*=-1;
    for(int i=0;i<v2.size();i++){
        cout<<W<<" "<<v2[i]<<endl;
        W-=v2[i];
    }
    }
    if(B==100000){
        v1.push_back(A);
        sort(v1.begin(),v1.end());
        cout<<po-v1[0]*2<<endl;
        cout<<v1[0]<<" "<<v1[1]<<endl;
        W=v1[0]-v1[1];
        for(int i=2;i<v1.size();i++){
            if(i==v1.size()-1){
                cout<<v1[i]<<" "<<W<<endl;
                return 0;
            }
            cout<<W<<" "<<v1[i]<<endl;
            W-=v1[i];
        }
    }
    
    if(A==100000){
        v2.push_back(B);
        sort(v2.begin(),v2.end());
        reverse(v2.begin(),v2.end());
        cout<<ne+v2[0]*2<<endl;
        cout<<v2[0]<<" "<<v2[1]<<endl;
        W=v2[0]-v2[1];
        for(int i=2;i<v2.size();i++){
            cout<<W<<" "<<v2[i]<<endl;
            W-=v2[i];
        }
    }
}
