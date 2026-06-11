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

int main(){
    int n,left,right;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<lint> from_left(n);
    vector<lint> from_right(n);
    for(int i=0;i<n;i++){
        left=i-a[i];
        right=i+a[i];
        if(0<=left)from_right[left]++;
        if(right<n)from_left[right]++;
    }
    lint ans=0;
    for(int i=0;i<n;i++){
        lint tmp=from_left[i]*from_right[i];
        ans+=tmp;
    }
    cout<<ans<<endl;
}
