#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

vector<int>v;
void gen(int val)
{
    if(val>1e10)
        return ;
    v.push_back(val);
    int dig=val%10;
    if(dig!=0 && dig!=9)
    {
        gen(val*10+dig);
        gen(val*10+dig+1);
        gen(val*10+dig-1);
        return ;
    }
    if(dig==0)
    {
        gen(val*10+dig);
        gen(val*10+dig+1);
    }
    else
    {
        gen(val*10+dig);
        gen(val*10+dig-1);
    }
}
int32_t main() 
{
    IOS;
    int k;
    cin>>k;
    for(int i=1;i<=9;i++)
        gen(i);
    sort(v.begin(),v.end());
    print(v[k-1]);
}   
