#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef pair<ll, ll> P;

int main(){
    ll n, sum=0;
    cin >> n;
    vec v(n); 
        for(int i=0; i<n; i++){
            cin >>  v.at(i);
            sum += v.at(i);
        }
    ll tmp=0, mini=sum;
        for(int i=0; i<n; i++){
            tmp += v.at(i);
            sum -= v.at(i);
            mini = min(abs(tmp-sum), mini);
        }

    cout << mini << endl;


    
}