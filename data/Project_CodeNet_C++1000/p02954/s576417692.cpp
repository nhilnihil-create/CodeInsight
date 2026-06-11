#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct edge{
    ll to, cost;
};


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

vector<bool> IsPrime;
void sieve(size_t max){
    if(max+1 > IsPrime.size()){
        IsPrime.resize(max+1,true);
    } 
    IsPrime[0] = false;
    IsPrime[1] = false;

    for(size_t i=2; i*i<=max; ++i){
        if(IsPrime[i]){
            for(size_t j=2; i*j<=max; ++j){
                IsPrime[i*j] = false;
            }
        }
    }
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    string s;
    cin>>s;

    vector<ll> count;
    ll r = 0, l = 0;
    bool flag = true;
    for(ll i=0;i<s.size();++i){
        if(flag == true){
            if(s[i] == 'R'){
                r++;
            }else if(s[i] == 'L'){
                flag = false;
                l++;
            }
        }else if(flag == false){
            if(s[i] == 'L'){
                l++;
            }else if(s[i] == 'R'){
                flag = true;
                count.push_back(r);
                count.push_back(l);
                r = 1;
                l = 0;
            }
        }
    }
    count.push_back(r);
    count.push_back(l);
    
    for(ll i=0;i<count.size();i+=2){
        ll sum = count[i] + count[i+1];
        for(ll j=0;j<count[i]-1;++j){
            cout<<0<<' ';
        }
        
        if(sum % 2 == 0){
            cout<<sum/2<<' '<<sum/2<<' '; 
        }else{
            if(count[i] % 2 == 1){
                cout<<sum/2+1<<' '<<sum/2<<' ';
            }else{
                cout<<sum/2<<' '<<sum/2+1<<' ';
            }
        }

        for(ll j=0;j<count[i+1]-1;++j){
            cout<<0<<' ';
        }
    }
    cout<<endl;

    return 0;
}