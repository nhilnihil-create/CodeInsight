#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

//template
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
#define ALL(v) (v).begin(),(v).end()
typedef long long int ll; typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename A,size_t N,typename T>void Fill(A(&array)[N],const T &val){fill((T*)array, (T*)(array+N), val);}
const int inf = INT_MAX / 2; const ll INF = LLONG_MAX / 2;
//template end

ll maxSubarrayXOR(vector<ll> set, int n) 
{ 
    // Initialize index of 
    // chosen elements 
    int index = 0; 
  
    // Traverse through all 
    // bits of integer  
    // starting from the most 
    // significant bit (MSB) 
    for (int i = 60; i >= 0; i--) 
    { 
        // Initialize index of 
        // maximum element and 
        // the maximum element 
        int maxInd = index; 
        ll maxEle = LLONG_MIN; 
        for (int j = index; j < n; j++) 
        { 
            // If i'th bit of set[j] 
            // is set and set[j] is  
            // greater than max so far. 
            if ( (set[j] & (1LL << i)) != 0  
                     && set[j] > maxEle ) 
                maxEle = set[j], maxInd = j; 
        } 
  
        // If there was no  
        // element with i'th 
        // bit set, move to 
        // smaller i 
        if (maxEle == LLONG_MIN) 
        continue; 
  
        // Put maximum element 
        // with i'th bit set  
        // at index 'index' 
        swap(set[index], set[maxInd]); 
  
        // Update maxInd and  
        // increment index 
        maxInd = index; 
  
        // Do XOR of set[maxIndex] 
        // with all numbers having 
        // i'th bit as set. 
        for (int j=0; j<n; j++) 
        { 
            // XOR set[maxInd] those 
            // numbers which have the 
            // i'th bit set 
            if (j != maxInd && 
               (set[j] & (1LL << i)) != 0) 
                set[j] = set[j] ^ set[maxInd]; 
        } 
  
        // Increment index of 
        // chosen elements 
        index++; 
    } 
  
    // Final result is  
    // XOR of all elements 
    ll res = 0; 
    for (int i = 0; i < n; i++) 
        res ^= set[i]; 
    return res; 
} 

int main(){
    int n; scanf("%d",&n);
    vector<ll> a(n);
    rep(i,0,n)scanf("%lld",&a[i]);
    ll s=0;
    rep(i,0,n)s^=a[i];
    ll ans=s;
    rep(i,0,n)a[i]&=(~s);
    ll add=maxSubarrayXOR(a,n);
    ans+=add*2LL;
    printf("%lld\n",ans);
    return 0;
}