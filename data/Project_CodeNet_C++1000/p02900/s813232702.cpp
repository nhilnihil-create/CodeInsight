#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


const ll mod=1000000007;

vector<int> fun(ll x){
    vector<int> vec;
    vec.push_back(1);
    for(ll a=2;a*a<=x;++a){
        if(x%a!=0)continue;
        while(x%a==0){
            x=x/a;
        }
        vec.push_back(a);
    }
    if(x!=1)vec.push_back(x);
    return vec;
}


int  main(){
    ll A,B;
    cin>>A>>B;

    vector<int> veca;
    vector<int> vecb;

    veca=fun(A);
    vecb=fun(B);
    /*
    for(int i=0;i<veca.size();++i){
        cout<<veca[i]<<" ";
    }
    cout<<endl;
    

       for(int i=0;i<vecb.size();++i){
        cout<<vecb[i]<<" ";
    }
    cout<<endl;
    */


    int count=0;

    for(int i=0;i<veca.size();++i){
        for(int j=0;j<vecb.size();++j){
            if(veca[i]==vecb[j]){
                ++count;
            }
        }
    }

   cout<<count<<endl;
     



 
}

