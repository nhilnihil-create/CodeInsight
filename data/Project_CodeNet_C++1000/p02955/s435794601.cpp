#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int maxn = 500+10;
LL a[maxn];
LL b[maxn];
LL ans = 1;
int n,k;

void update(LL x){
    LL ss=0,sss=0;
    vector<int>s;
    for(int i=1;i<=n;i++)s.push_back(a[i]%x),sss+=x-a[i]%x;
    sort(s.begin(),s.end());
    ss=s[0],sss-=x-s[0];
    for(int i=1;i<s.size();i++){
        if(ss+s[i]>k)break;
        ss+=s[i],sss-=x-s[i];
    }
     if(ss<=k&&sss<=k)ans=max(ans,x);
}
int main(void)
{
    cin>>n>>k;
    LL sum = 0;
    for(int i = 1;i <= n; ++i)
        cin>>a[i],sum += a[i];
    // cout<<sum<<endl;
    for(LL i = 2;i*i <= sum; ++i){
        if(sum % i == 0){
            update(i);
            update(sum/i);
        }
    }
    update(sum);

    cout<<ans<<endl;

    return 0;
}

