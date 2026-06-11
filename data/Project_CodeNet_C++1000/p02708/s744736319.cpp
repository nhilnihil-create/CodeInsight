#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    lint n,k,ans=0;cin>>n>>k;
    lint left_sum=(k*(k-1)/2);int left=k-1;
    lint right_sum=((n-k+1)+n)*k/2;int right=n-k+1;
    for(int i=k;i<=n+1;i++){
        ans+=right_sum-left_sum+1;
        ans%=1000000007;
        left_sum+=(left+1);left++;
        right_sum+=(right-1);right--;
    }
    cout<<ans<<endl;
}
