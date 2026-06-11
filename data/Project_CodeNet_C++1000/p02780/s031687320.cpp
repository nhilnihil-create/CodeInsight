#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    for(int i=0; i<n; i++){
        cin >> p.at(i);
    }
    ll sum_p=0;
    for(int i=0; i<k; i++){
        sum_p+=p.at(i);
    }
    ll max_sum=sum_p;
    for(int i=0; i<n-k; i++){
        sum_p = sum_p - p.at(i) + p.at(i+k);
        if(sum_p > max_sum){
            max_sum = sum_p;
        }
    }
    if((k+max_sum) % 2 == 0){
        cout << (k+max_sum)/2 << endl;
    }
    else{
        cout<<fixed<<setprecision(8)<<(k+max_sum)/2+0.50000000<< endl;
    }
}
