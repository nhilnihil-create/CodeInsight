#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std;

using ll = long long;
using boost::irange;

#define MOD 1000000007
#define L true
#define R false

ll factorial(int n){
    ll ans = 1;
    for(auto i : irange(1,n+1)){
        ans *= i;
        ans %= MOD;
    }

    return ans;
}

int main(void){
    
    int N;
    string S;
    cin >> N >> S;
    vector<bool> d(2*N, false);
    vector<int> ind;

    if(S[0] == 'W' || S[d.size()-1] == 'W'){
        cout << "0" << endl;
      	return 0;
    }

    d[0] = L;
    for(const auto i : irange(0, 2*N-1)){
        if(S[i] == S[i+1]){
            d[i+1] = !d[i];
        }else{
            d[i+1] = d[i];
        }
        if(d[i+1] == R){
            ind.push_back(i+1);
        }
    }

    ll ans = 1;
    int l = 0;
    int r = 0;
    bool flag = false;
    for(int i = 0; i < 2*N; i++){
        if (d[i] == L){
            l++;
        }else{
            ans *= (l - r);

            if (ans <= 0){
                flag = false;
                break;
            }

            ans %= MOD;
            r++;
            flag = true;
        }      
    }

    if(flag == false || l != r){
        cout << "0" << endl;
        return 0;
    }


    ans *= factorial(N);
    ans %= MOD;

    cout << ans << endl;

    return 0;
}