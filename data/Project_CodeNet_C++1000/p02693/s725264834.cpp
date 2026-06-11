//Moh_K_Imar .......
//22/08/2020  ... 11.38
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    ll k,a,b;
    cin>>k>>a>>b;
    ll counter=0;
    for(int i=a;i<=b;i++){
        if(i%k==0){
            counter++;
        }
    }
    if(counter!=0)cout<<"OK"<<endl;
    else cout<<"NG"<<endl;


    return 0;
}

