#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n; cin>>n;
    int kind = 0;
    map<ll, ll> list;
    for(int i=0; i<n; i++){
        ll a; cin>>a;
        if(list.count(a)) list[a]+=1;
        else{
            list[a]=1;
            kind ++;
        }
    }
    if(kind>3) cout << "No" << endl;
    else if (kind==3){
        auto iter = list.begin();
        ll a1 = iter->first, a1_n=iter->second; iter++;
        ll a2 = iter->first, a2_n=iter->second; iter++;
        ll a3 = iter->first, a3_n=iter->second;
        if(a1_n==a2_n && a2_n==a3_n){
            if(((a1^a3)^a2)==0) cout << "Yes" << endl; //ここだけがおかしい
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }
    else if(kind==2){
        auto iter = list.begin();
        ll a1 = iter->first, a1_n=iter->second; iter++;
        ll a2 = iter->first, a2_n=iter->second;
        if(a1==0){
            if (a1_n*2==a2_n) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else cout << "No" << endl;
    }
    else if(kind==1){
        if(list.count(0)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}