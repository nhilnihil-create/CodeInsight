#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
using ll = long long;
template <typename T>T digitsum(T n);
template <typename T>T gcd(T u,T v);
template <typename T>bool isPrime(T n);
template <typename T>vector<pair<T, T>> prime_factor(T n);
long long int intpow(long long int,long long int);
template <typename T>T intlog(T);

int main(){
    int n,ans=1,j;
    cin>>n;
    vector<int> vec(n);
    vector<bool> vec2(n,true);
    con_input(vec);
    rep(i,n-1){
        if(vec[i]-vec[i+1]>=2){
            ans=0;
            break;
        }
        if(vec[i]-vec[i+1]==1){
            vec[i]--;
            vec2[i]=false;
            j=i;
            while(j>=1&&vec[j-1]>vec[j]){
                if(vec2[j-1]){
                    vec[j-1]--;
                    vec2[j-1]=false;
                    j--;
                }else{
                    ans=0;
                    break;
                }
            }
        }
        if(ans==0)break;
    }
    cout<<(ans?"Yes":"No")<<endl;
}
