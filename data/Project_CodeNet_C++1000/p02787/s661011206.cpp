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

//(*'ω'*)ACください
int main(){
    int h,n;cin>>h>>n;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++)cin>>a[i]>>b[i];
    vector<int> minMP(h+1,1000000000);
    minMP[0]=0;
    for(int i=1;i<=h;i++){
        for(int j=0;j<n;j++){
            int from=i-a[j];
            if(from<0)from=0;
            minMP[i]=min(minMP[i],minMP[from]+b[j]);
        }
    }
    cout<<minMP[h]<<endl;
}
