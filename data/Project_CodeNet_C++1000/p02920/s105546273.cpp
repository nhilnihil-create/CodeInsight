#include <bits/stdc++.h>

using namespace std;
#define IOS ios::sync_with_stdio(false)
#define all(x) x.begin(),x.end()
#define pb push_back
#define mp make_pair
#define pii pair<int,int>

int main()
{
    IOS;
    int n;
    cin>>n;
    vector<int> a(1<<n);
    for(int i=0;i<1<<n;i++)cin>>a[i];
    sort(all(a));
//    for(auto x:a)cout<<x<<" ";
//    cout<<endl;
    bool ok=1;
    vector<int> pre;
    int m=1<<n;
    if(a[m-1]>a[m-2]){
        pre.pb(a[m-1]);
        pre.pb(a[m-2]);
    }else {
        ok=0;
    }
    multiset<int> st;
    for(int i=0;i<m-2;i++)st.insert(a[i]);
    for(int i=1;i<n;i++){
        vector<int> now;
        for(int j=0;j<pre.size();j++){
            auto it=st.lower_bound(pre[j]);
            if(it==st.begin()){
//                cout<<i<<" "<<j<<" "<<pre[j]<<endl;
                ok=0;
                break;
            }
            --it;
            now.pb(*it);
            st.erase(it);
        }
        if(!ok)break;
        pre.insert(pre.end(),all(now));
    }
    if(ok)puts("Yes");
    else puts("No");
    return 0;
}
