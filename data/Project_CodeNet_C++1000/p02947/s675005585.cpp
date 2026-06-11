/**-------------------------
|--------From A.R.A--------|
-------------------------**/

#include <bits/stdc++.h>

#define ll            long long int
#define pb            push_back
#define ull           unsigned long long int
#define endl          "\n"
#define sz(c)         (c).size()
#define sall(c)       sort((c).begin(),(c).end())
#define rsall(c)      sort((c).rbegin(),(c).rend())
#define rev(c)        reverse((c).begin(),(c).end())
#define FOR(i,n)      for(ll i=0;i<n;i++)
#define max3(a,b,c)   max(max(a,b),c)
#define min3(a,b,c)   min(min(a,b),c)
#define input(a,i,n)  for(ll i=0;i<n;i++){      cin>>a[i];}
#define output(a,i,n) for(ll i=0;i<n;i++){cout<<a[i]<<" ";}

using namespace std;
int64_t R=1;
void solution(){
    int64_t n,sum=0;
    cin>>n;
    string s;
    map <string,int64_t> m1;
    for(int i=0;i<n;i++){
        cin>>s;sall(s);
        m1[s]++;
    }
    for(auto i:m1){
        int64_t x=i.second-1;
        sum+=((1+x)*x)/2;
    }
    cout<<sum<<endl;

}
int main()
{
    FOR(i,R){solution();}
    return 0;
}