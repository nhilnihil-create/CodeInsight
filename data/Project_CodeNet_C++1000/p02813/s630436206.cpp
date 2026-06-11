using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define EL '\n'
#define el '\n'
#define all(x) x.begin(),x.end()
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define repd(i, a, b) for (ll i = (b)-1; i >= (a); i--)
#define large 1000000007
#define MOD 1000000007
#define pb push_back
#define MAX 10e+7
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
void solve()
{
int n;
cin>>n;
string s1,s2;
for (int i = 0; i < n; i++)
{
    int a;
    cin>>a;
    s1+=a;
}
for (int i = 0; i < n; i++)
{
    int a;
    cin>>a;
    s2+=a;
}
string s11=s1,s22=s2;
sort(s1.begin(),s1.end());
sort(s2.begin(),s2.end());
int ans1=0,ans2=0;
do
{
    ans1++;
    if(s1==s11)
    goto end;
} while (next_permutation(s1.begin(),s1.end()));
end:
do
{
ans2++;
if(s2==s22)
goto end1;
} while (next_permutation(s2.begin(),s2.end()));
end1:
cout<<abs(ans1-ans2)<<endl;
}
int main()
{

FASTIO
 long long int t;
 t=1;
 while(t--)
 {
  solve();
  
 }
  return 0;
}
