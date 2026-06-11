#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#define all(x) (x).begin(), (x).end()
typedef long long ll;
#define MOD 1000000007
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<ll> a, b;
    ll ans=0;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp < 0)
        {
            b.push_back(tmp);
            ans-=tmp;
        }
        else
        {
            a.push_back(tmp);
            ans+=tmp;
        }
    }
    sort(all(a));
    sort(all(b),greater<ll>());
    if(b.empty()){
        cout<<ans-2*a[0]<<endl;
        ll hoge=a[0];
        for(int i=1;i<a.size()-1;i++){
            cout<<hoge<<" "<<a[i]<<endl;
            hoge-=a[i];
        }
        cout<<a.back()<<" "<<hoge<<endl;
    }
    else if(a.empty()){
        cout<<ans+2*b[0]<<endl;
        ll hoge=b[0];
        for(int i=1;i<b.size();i++){
            cout<<hoge<<" "<<b[i]<<endl;
            hoge-=b[i];
        }
    }
    else{
        cout<<ans<<endl;
        ll hoge=b[0];
        for(int i=0;i<a.size()-1;i++){
            cout<<hoge<<" "<<a[i]<<endl;
            hoge-=a[i];
        }
        cout<<a.back()<<" "<<hoge<<endl;
        hoge=a.back()-hoge;
        for(int i=1;i<b.size();i++){
            cout<<hoge<<" "<<b[i]<<endl;
            hoge-=b[i];
        }
    }
}