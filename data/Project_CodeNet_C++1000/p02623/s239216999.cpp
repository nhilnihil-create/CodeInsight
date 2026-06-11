#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,K;
    cin>>n>>m>>K;
    vector<long long> a(n+1,0),b(m+1,0);
    // vector <int> in(n+m);
    for(int i = 1;i<=n;i++)
    {
    cin>>a[i];
    a[i] += a[i-1];
    }
    for(int i = 1;i<=m;i++)
    {
    cin>>b[i];
    b[i] += b[i-1];
    }
    vector<long long>::iterator it;
    long long count  =0;
    long long  ans = 0;
    long long max = m;
    int j = max;
    for(long long i = 0;i<=n;i++)
    {
        // if(a[i]<=k)
        // {
        //     it =  lower_bound(b.begin(), b.end(), k-a[i]);
        //    if(a[i]+*it>k)
        //   it--;
        //   count = i+(it - b.begin());
        // //   cout<<i<<endl;

        // }
        // else
        // {
        //  it = lower_bound(b.begin(), b.end(), k);
        //  if(*it>k)
        //  it--;
        //  count =  it - b.begin();
        // //  cout<<*it<<endl;

        // }
        // if(count > max)
        // max = count;
          while(a[i] + b[j] > K) {
        j--;
        if(j < 0) { j = max; break; }
      }
      if(a[i] + b[j] <= K) {
         max = j; 
        if(ans < i + j) ans = i + j;
         }
    }
    cout<< ans;
   

    return 0;
}