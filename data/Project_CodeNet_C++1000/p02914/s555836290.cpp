#include <assert.h>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using ll = long long;
using P = std::pair<ll, ll>;

#define rep(i, a, b) for (ll(i) = (a); i < (b); i++)
#define all(i) i.begin(), i.end()
#define debug(i) std::cerr << "debug "<< i << std::endl

//const ll MOD = 998244353;
const ll MOD = 1e9 + 7;

// Function to return 
// maximum XOR subset 
// in set[] 
ll maxSubarrayXOR(ll set[], ll n) 
{ 
    // Initialize index of 
    // chosen elements 
    ll index = 0; 
  
    // Traverse through all 
    // bits of lleger  
    // starting from the most 
    // significant bit (MSB) 
    for (ll i = 60; i >= 0; i--) 
    { 
        // Initialize index of 
        // maximum element and 
        // the maximum element 
        ll maxInd = index; 
        ll maxEle = INT_MIN; 
        for (ll j = index; j < n; j++) 
        { 
            // If i'th bit of set[j] 
            // is set and set[j] is  
            // greater than max so far. 
            if ( (set[j] & ((ll)1 << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
  
        // If there was no  
        // element with i'th 
        // bit set, move to 
        // smaller i 
        if (maxEle == INT_MIN) 
        continue; 
  
        // Put maximum element 
        // with i'th bit set  
        // at index 'index' 
        std::swap(set[index], set[maxInd]); 
  
        // Update maxInd and  
        // increment index 
        maxInd = index; 
  
        // Do XOR of set[maxIndex] 
        // with all numbers having 
        // i'th bit as set. 
        for (ll j=0; j<n; j++) 
        { 
            // XOR set[maxInd] those 
            // numbers which have the 
            // i'th bit set 
            if (j != maxInd && 
               (set[j] & ((ll)1 << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        index++; 
    } 
  
    // Final result is  
    // XOR of all elements 
    ll res = 0; 
    for (ll i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  //問題文中の添え字が0-indexか1-indexか確認!

  ll n,ans=0;
  std::cin>>n;

  std::vector<ll> a(n),check;

  rep(i,0,n){
    std::cin>>a[i];
    ans=(ans^a[i]);
  }

  ll set[100000]={0};

  rep(i,0,60)if(!((ans>>i)&1))check.push_back(i);

  rep(i,0,n){
    ll temp=0;
    rep(j,0,check.size()){
      if((a[i]>>check[j])&1)temp+=((ll)1<<check[j]);
    }
    set[i]=temp;
  }

  ans+=(maxSubarrayXOR(set,100000))<<1;

  std::cout<<ans;

  return 0;
}
