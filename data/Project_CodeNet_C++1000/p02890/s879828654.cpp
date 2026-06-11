#include <bits/stdc++.h>
#define mk make_pair
#define fs first
#define sc second
using namespace std;
typedef long long ll;
typedef long double ld;
int a[300010], mp[300010], trakm[300010];
vector <int> v;
int sz;
int ans[300010];
int main(){
    int n;
    while(cin>>n){
        memset(ans, 0, sizeof ans);
        for(int i=0; i<n; ++i){
            scanf("%d",a+i);
            ++mp[a[i]];
        }
        for(int i=0; i<=n; ++i){
            v.push_back(mp[i]);
        }
        sz=v.size();
        sort(v.begin(), v.end());
        trakm[0]=v[0];
        for(int i=1; i<v.size(); ++i){
            trakm[i]=trakm[i-1]+v[i];
        }
        int tmp;
        for(int i=1; i<=n; ++i){
            tmp=lower_bound(v.begin(), v.end(), i)-v.begin();
            ans[sz-tmp+trakm[tmp-1]/i]=i;
        }
        for(int i=n-1; i>=1; --i){
            ans[i]=max(ans[i], ans[i+1]);
        }
        for(int i=1; i<=n; ++i){
            printf("%d\n",ans[i]);
        }
    }
  return 0;
}


