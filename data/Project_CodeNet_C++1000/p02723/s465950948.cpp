//Moh_K_Imar .......
//22/08/2020  ... 11,54 .
//Ya Rab....
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
int main(){
    string a;
    cin>>a;
    ll counter=0;
    for(int i=0;i<a.size();i++){
        if(a[2]==a[3]&&a[4]==a[5]){
            counter++;
        }
    }
    if(counter!=0)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}

