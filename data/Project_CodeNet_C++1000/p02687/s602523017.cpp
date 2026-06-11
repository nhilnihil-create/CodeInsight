#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define mod 1000000007
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define inp_vecN for(int i=0;i<n;i++)cin>>v[i]; 
vector<int> get_Factors(ll n)
{
      vector <int> v;
      for(ll i=2; i<=sqrt(n)+1; i++)
      {
            if(n%i==0)
            {
                  v.push_back(i);
                  v.push_back(n/i);
            }
      }

      v.push_back(1);

      return v;
}
string get_bin(ll n)
{
    string s = "";
    while(n > 0)
    {
        s += ('0' + n%2);
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

ll bin_to_dec(string s)
{
    ll ans = 0;
    for(auto ch: s)
    {
        ans *= 2;
        ans += (ch - '0');
    }
    return ans;
}
void PrintVector(vector<int> v,int n)
{

    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int no_of_primeFactors(int n)  
{ 
    int count=0;
    while (n % 2 == 0)  
    {  
        count++;
        n = n/2;  
    }  
   
    for (int i = 3; i <= sqrt(n); i = i + 2)  
    { 
        while (n % i == 0)  
        {  
           count++;
            n = n/i;  
        }  
        
    }  
    if (n > 2)  
        count++;
    return count;
} 
 ll gcd(int a, int b)
{ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
} 
   
  ll lcm(int a, int b)  
{  
    return (a/gcd(a, b)*b);  
}  



ll pwr(ll base,ll expo,ll m)
{
    if(base==0) return 0LL;
    if(expo==0) return (1LL%m);
    if((expo&1)==0) {ll temp=pwr(base,expo>>1,m); return (temp*temp)%m;}
    return ((base%m)*pwr(base,expo-1,m))%m;
}

int main(int argc, char const *argv[])
{
    ios;
    
    string s;
    cin>>s;
    if(s=="ABC")
      cout<<"ARC";

      else
            cout<<"ABC";
    return 0;
}