 #include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool ispal(string a)
{
    long long int n=a.length();
    if(n==1)
        return true;
    else{
    int i=0,j;
    j=n-1;
    while(1)
    {
        if(a[i]!=a[j])
        {
            cout<<i<<" "<<j;
           return false;
        }
        i++,j--;
        if(i==j)
         {
        //     cout<<i<<" ";
             break;
        }
    }
    return true;
}}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll n;
  cin>>n;
    vector<pair<ll,ll> >v(n);
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[i]={a,b};
    }
    sort(v.begin(),v.end());
    double tm=0;
    do{
        for(int i=0;i<n-1;i++)
        {
            ll x1=v[i].first,x2=v[i+1].first,y1=v[i].second,y2=v[i+1].second;
            double dis = sqrt(((x1-x2)*(x1-x2)) + ((y1-y2)*(y1-y2)));
            tm+=dis;
        }
    }
    while(next_permutation(v.begin(),v.end()));
    ll tp=1;
 for(int i=1;i<n;i++)
 {
     tp*=i+1;
 }
    cout<<std::fixed<<setprecision(10)<<tm /(tp);
  }
