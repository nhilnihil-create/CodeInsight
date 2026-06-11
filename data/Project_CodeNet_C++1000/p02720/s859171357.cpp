#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void make_lunlun(int d, ll i, vector<ll> &all){
    if(d==11) return;
    all.push_back(i);
    if(i%10 == 0){
        make_lunlun(d+1,i*10+(i%10),all);
        make_lunlun(d+1,i*10+(i%10)+1,all);
    }
    else if(i%10 == 9){
        make_lunlun(d+1,i*10+(i%10)-1,all);
        make_lunlun(d+1,i*10+(i%10),all);
    }
    else{
        make_lunlun(d+1,i*10+(i%10)-1,all);
        make_lunlun(d+1,i*10+(i%10),all);
        make_lunlun(d+1,i*10+(i%10)+1,all);
    }
}

int main(){
    int k;
    cin >> k;
    vector<ll> lunlun;
    for(ll i=1; i<=9; i++){
        make_lunlun(1, i, lunlun);
    }
    sort(lunlun.begin(), lunlun.end());
    cout << lunlun.at(k-1) << endl;

    /*
    for(int i=0; i<15; i++){
        cout << lunlun.at(i) << endl;
    }
    */
}
