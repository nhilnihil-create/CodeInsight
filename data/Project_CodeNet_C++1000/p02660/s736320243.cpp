/*
2020/7/21
7/23
*/

#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    long long N;
    cin >> N;
    vector<pair<ll,ll> > prime;
    long long i=2;
    while(i*i<=N){
        if(N%i==0){
            int count=0;
            while(N%i==0){
                N/=i;
                count++;
            }
            prime.push_back({i,count});
        }
        i++;
    }
    if(N!=1) prime.push_back({N,1});
    int ans=0;
    for(auto kani : prime){
        int i=1;
        while(kani.second-i>=0){
            ans++;
            kani.second-=i;
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}