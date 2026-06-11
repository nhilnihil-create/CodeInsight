#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
#define ll long long

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fast()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
}

const int P = 1e9 + 7;

int main(int argc, char const *argv[])
{
    // file();
    
    ll n, k;cin>>n>>k;
    ll A[2002];

    for (int i = 0; i < n; ++i)
    {
        cin>>A[i];
    }
    
    ll self_inv = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            self_inv+=A[i] > A[j];
        }
    }

    ll type1_inv = (self_inv % P * k % P) % P; // self inverse * number of copies

    ll cp_inv = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cp_inv+=A[i] > A[j];
        }
    }
    ll pairs_cnt = (k * (k - 1))  / 2 % P; // number of ways to choose pair
    ll type2_inv = (pairs_cnt % P * cp_inv % P) % P; // inverse_between_pair * number_of_pairs

    cout<<(type1_inv % P + type2_inv % P) % P;
}