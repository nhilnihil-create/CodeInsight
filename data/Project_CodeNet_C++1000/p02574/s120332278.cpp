#include <bits/stdc++.h>
#include <iomanip>
#define M 1000001
#define MAX 1000000001
#define MIN -10000000000000000
#define mod 1000000007
#define ss second
#define ff first
#define ll long long int
#define pb push_back
#define ld double
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vector<int>primes;
ll gcd(ll a,ll b){
    if(a == 0 || b == 0)
        return (a+b);
    if(a < b)
        swap(a,b);
    return gcd(b,a%b);
}

void find_primes(){
    bool check[M] = {0};
    for(int i=2;i<M;i++){
        if(check[i] == false){
            primes.pb(i);
            for(int j=i+i;j<M;j+=i)
                check[i] = true;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int fr[M] = {0};
    ll g = 0;
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        fr[temp]++;
        g = gcd(g,temp);
    }
    if(g == 1){
        find_primes();
        bool pairwise = true;
        for(int i:primes){
            ll cnt = 1,current = i,count = 0;
            while(current < M){
                count += fr[current];
                if(count >= 2){
                    pairwise = false;
                    break;
                }
                current += i;
            }
            if(!pairwise)
                break;
        }
        if(pairwise)
            cout<<"pairwise coprime\n";
        else
        {
            cout<<"setwise coprime\n";
        }
        
    }
    else{
        cout<<"not coprime\n";
    }
    return 0;
        
}
