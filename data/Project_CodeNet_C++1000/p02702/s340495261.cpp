#include <bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

bool sortbysec_2(const pair<string,int> &a, 
              const pair<string,int> &b) 
{ 
    return (a.second < b.second); 
} 
bool sortinrev(const pair<int,int> &a,  
               const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 
bool sortbysecdesc(const pair<int,int> &a, 
                   const pair<int,int> &b) 
{ 
       return a.second>b.second; 
} 
double distance(int x1, int y1, int x2, int y2) 
{ 
    return sqrt(pow(x2 - x1, 2) +  
                pow(y2 - y1, 2) * 1.0); 
} 
#define ll long long int
#define ld long double
#define f first
#define s second
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll64 int64_t
#define pb push_back
#define pll pair<long long int,long long int>
#define pi pair<int,int>
#define mi map<int,int>
#define mll map<long long int,long long int>
#define umi unordered_map<int,int>
#define umll unordered_map<long long int,long long int>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<long long int,long long int>>
#define mod 1000000007
#define fp(i,x,n) for(int i=x;i<n;i++)
#define fn(i,x,n) for(int i=x;i>n;i--)
#define fpm(i,m) for(auto i=m.begin();i!=m.end();i++)
#define asort_vp_second(vect) sort(vect.begin(), vect.end(), sortbysec)
#define asort_vp_first(vect) sort(vect.begin(), vect.end())
#define dsort_vp_first(vect) sort(vect.begin(), vect.end(), sortinrev) 
#define dsort_vp_second(vect) sort(vect.begin(), vect.end(), sortbysecdesc)
#define vi vector<int>
#define vld vector<long double>
#define asort(v) sort(v.begin(),v.end())
#define dsort(v) sort(v.begin(),v.end(),greater<int>())
#define dsort_ll(v) sort(v.begin(),v.end(),greater<long long int>())
#define dsort_ld(v) sort(v.begin(),v.end(),greater<long double>())
#define vll vector<long long int>
#define mp(a,b) make_pair(a,b)

int main() {
    FIO;
   string s;
   cin>>s;
   int n = s.size();
   
   int suf=0;
   int power =1;
   vector<int> v(2019);
   v[suf]++;
   long long ans=0;
   for(int i=n-1;i>=0;i--)
   {
       int digit = s[i] -'0';
       suf = (suf + digit*power)%2019;
       power = power*10 %2019;
       ans+=v[suf];
       v[suf]++;
   }
   cout<<ans<<endl;
}