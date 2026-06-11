#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define print(A,n) for(ll i=0;i<n;++i)cout<<A[i]<<' ';cout<<endl;
#define take(A,n) for(ll i=0;i<n;++i)cin>>A[i];
//    for(auto& it : m)
void fastio(){ios_base::sync_with_stdio(false);cin.tie(NULL);}
//  priority_queue<ll int> pq;
//  priority_queue <ll int, vector<ll int>, greater<ll int> > pq;
//  vector<ll int> v;
//  vector< pair<ll int,ll int> > v;
//  set<ll int>::iterator it=s.begin();
//  unordered_map<  pair<ll int,ll int>, ll int> mp;

 

ll int power(ll int x, ll int y, ll int p)  
{  
    ll int res = 1;     // Initialize result  
  
    x = x % p; // Update x if it is more than or  
                // equal to p 
   
    if (x == 0) return 0; // In case x is divisible by p; 
  
    while (y > 0)  
    {  
        // If y is odd, multiply x with result  
        if (y & 1)  
            res = (res*x) % p;  
  
        // y must be even now  
        y = y>>1; // y = y/2  
        x = (x*x) % p;  
    }  
    return res;  
}  

void computeLPSArray(string pat, int M, int* lps) 
{ 
    // length of the previous longest prefix suffix 
    int len = 0; 
  
    lps[0] = 0; // lps[0] is always 0 
  
    // the loop calculates lps[i] for i = 1 to M-1 
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider the example. 
            // AAACAAAA and i = 7. The idea is similar 
            // to search step. 
            if (len != 0) { 
                len = lps[len - 1]; 
  
                // Also, note that we do not increment 
                // i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}
bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
  

int main()
{
  fastio();

 
ll int T;
T=1;

while(T--)
{ 
ll int n,k,i,flag=1;
cin>>n>>k;
ll int a[n];
for(i=0;i<n;i++)
  cin>>a[i];

while(k--)
{
  int f=0;
  ll int b[n]={0};
  
  for(i=0;i<n;i++)
  {
    if(a[i]==0)continue;
    b[max(i-a[i],0ll)]++;
    b[max(i,0ll)]--;
    if(i+1<n){
      b[i+1]++;
        if(a[i]+i+1<n)
        b[a[i]+i+1]--;}


  }
  for(i=1;i<n;i++)
    b[i]+=b[i-1];
 
  

        for(i=0;i<n;i++)
    {a[i]=b[i]+1;if(a[i]<n)f=1;}
    if(!f)break;


}
for(i=0;i<n;i++)
  cout<<a[i]<<" ";
}





    
  



    return 0;
}
