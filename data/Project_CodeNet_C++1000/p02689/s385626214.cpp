#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m;

   cin>>n>>m;
vector<int> h(n);
vector<int> f(m);
vector<int> s(m);
vector<bool> e(n);
int ans=0;
for (int i = 0; i < n; i++)
{
    cin>>h[i];
}
for (int i = 0; i < m; i++)
{
    cin>>f[i]>>s[i];
   
}
for (int i = 0; i < m; i++)
{
   int one=f[i]-1;
   int two=s[i]-1;
   if(h[one]>h[two]){
e[two]=1;
}
if(h[one]<h[two]){e[one]=1;}
if(h[one]==h[two]){e[one]=1;e[two]=1;}

}
for (int i = 0; i < n; i++)
{
if(e[i]==0)ans++;


}
cout<<ans<<endl;

}