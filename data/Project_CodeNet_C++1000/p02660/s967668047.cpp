#include<bits/stdc++.h>
using namespace std;
#define f first 
#define s second 
#define int long long
#define pb push_back
#define mp make_pair
#define pi pair<int , int>
set<pi> st;
void factorize(long long n) 
{ 
    int count = 0; 
  
    // count the number of times 2 divides  
    while (!(n % 2)) { 
        n >>= 1; // equivalent to n=n/2; 
        count++; 
    } 
  
    // if 2 divides it 
    if (count) 
    st.insert({2 , count});
        // cout << 2 << "  " << count << endl; 
  
    // check for all the possible numbers that can  
    // divide it 
    for (long long i = 3; i <= sqrt(n); i++) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
        st.insert({i , count});
            // cout << i << "  " << count << endl; 
    } 
  
    // if n at the end is a prime number. 
    if (n > 2) 
    st.insert({n , 1});
        // cout << n << "  " << 1 << endl; 
} 
int32_t main(){
     int n;
     cin>>n;
     factorize(n);
     int ans = 0;
     int rem = 0;
     for(auto it:st){
           int sum =  it.second;
        //   cout<<"sum : "<<sum;
           int val = sqrtl(sum);
        //   cout<<" val : "<<val<<endl;
           while((val*(val+1))/2 <= sum){
               val++;
           }
           val--;
          ans += val;
     }
     cout<<ans<<endl;
}
