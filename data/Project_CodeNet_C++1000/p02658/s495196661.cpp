#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    double nb_dig = 0;
    cin>>n;
    vector<long long> v(n);
    for(int i = 0;i<n;++i){
        cin>>v[i];
        nb_dig += log10(v[i]);
    }
    sort(v.begin(),v.end());
    if(!v[0]){
        cout<<0;
        return 0;
    }
    if(nb_dig>19){
        cout<<-1;
        return 0;
    }
    long long res = 1;
    for(int i = 0;i<n;++i){
        if(v[i]>(long long)(1e+18)/res){
            cout<<-1;
            return 0;
        }
        res *= v[i];
    }
    cout<<res;
    return 0;
}